#include<stdio.h>
#include<limits.h>

int main(){
    int n,i,j;
    int at[20],bt[20],ct[20],tat[20],wt[20],rt[20],p[20];

    printf("Enter no of process: ");
    scanf("%d", &n);

    printf("Enter arrival time:\n");
    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("p%d: ",i+1);
        scanf("%d", &at[i]);
    }

    printf("Enter the burst time:\n");
    for(i=0;i<n;i++){
        printf("p%d: ",i+1);
        scanf("%d", &bt[i]);
    }

    // Sort by arrival time
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++){
        if(ct[i-1] < at[i])
            ct[i]=at[i]+bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        rt[i]=wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    return 0;
}