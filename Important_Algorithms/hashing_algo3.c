#include <stdio.h>

#define SIZE 7  // Size of the Hash Table (Using a prime number is best)
#define EMPTY -1 // -1 means the slot is completely empty

// The Hash Table array
int hashTable[SIZE];

// 1. The Hash Function: Simple modulo arithmetic
int hashFunction(int key) {
    return key % SIZE;
}

// 2. Insert function using Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int startPosition = index; // Remember where we started to avoid infinite loops

    // Linear Probing: If the slot is taken, move to the next index (+1)
    while (hashTable[index] != EMPTY) {
        index = (index + 1) % SIZE; // Move to next slot, wrap around to 0 if at the end

        // If we loop all the way back to the start, the table is completely full!
        if (index == startPosition) {
            printf("Table Full! Could not insert key %d\n", key);
            return;
        }
    }

    // Place the key into the empty slot found
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// 3. Search function using Linear Probing
int search(int key) {
    int index = hashFunction(key);
    int startPosition = index;

    // Keep checking slots lineary until we find the key or hit an EMPTY slot
    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return index; // Found the key! Return its index
        }
        
        index = (index + 1) % SIZE; // Move to the next slot

        // If we loop back to where we started, the key is not in the table
        if (index == startPosition) {
            break;
        }
    }

    return -1; // Key was not found
}

int main() {
    // Initialize the hash table slots to be completely empty
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    printf("--- Inserting Keys ---\n");
    insert(12); // 12 % 7 = 5 -> goes to index 5
    insert(26); // 26 % 7 = 5 -> index 5 is full! Probes to index 6
    insert(19); // 19 % 7 = 5 -> index 5 and 6 are full! Wraps around and probes to index 0
    insert(9);  // 9 % 7 = 2  -> goes straight to index 2

    printf("\n--- Hash Table Status ---\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("Index %d: EMPTY\n", i);
        } else {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }

    printf("\n--- Searching for Keys ---\n");
    int target = 26;
    int foundIndex = search(target);
    if (foundIndex != -1) {
        printf("Key %d found at index %d\n", target, foundIndex);
    } else {
        printf("Key %d not found\n", target);
    }

    return 0;
}
