#include <stdio.h>

int minindex(int keys[],int isMST[]){
    int min=10000;
    int min_index=-1;
    for(int i=0;i<7;i++){
        if(keys[i]<min && isMST[i]==0){
            min=keys[i];
            min_index=i;
        }
    }
    return min_index;
}

void prims(int A[7][7]){
    int parent [7];
    int isMST [7];
    int keys [7];
    for(int i=0;i<7;i++){
        isMST[i]=1000;
        int keys[i]=0;
    }
    int parent[0]=-1;
    int keys[0]=0;
    for(int i=0;i<6;i++){
        int u=minindex(keys,isMST);
        inMST[u]=1;
        for(int j=0;j<7;j++){  //parents loop
        if(A[u][j]<keys[j] && A[u][j]!=0 && inMST[j] ){
            parent[j]=u;
            key[j]=A[u][j];
        }
    }
}
printf("Edge\tWeight\n");
int totalCost=0;
for(int i=1;i<7;i++){
    printf("%d - %d \t%d \n",parent[i],i,A[i][parent[i]]);
    totalCost+=A[i][parent[i]];
}
printf("Total Cost of MST: %d",totalCost);
}
int main() {
    
    return 0;
}