#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include <time.h>  

#define MAX 1000000

int table[MAX][20];

void fillTable(int v[], int n){
    int i, j;

    //intervale de lungime 1
    for(i=0; i<n; i++){
        table[i][0] = v[i];
    }

    //salveaza minimul de la fiecare index pana la fiecare putere a lui 2.
    for(j=1; (1<<j)<=n; j++){
        for(i=0; (i+(1<<j)-1)<n; i++){
            if(table[i][j-1]<table[i+(1<<(j-1))][j-1]){
                table[i][j] = table[i][j-1];
            }
            else{
                table[i][j] = table[i+(1<<(j-1))][j-1];
            }
        }
    }
}

int query(int left, int right){

    int j = log2(right-left+1);

    if(table[left][j]<=table[right - (1 << j) + 1][j]){
        return table[left][j];
    }
    return table[right - (1 << j) + 1][j];
}

int main(){

    FILE *fi;
    FILE *fo;        
    FILE *fo2; 

    float start_t, end_t, total_t=0.0;

    //Test1
    int *v = calloc(4, MAX);
    fi = fopen("in/test1.in", "r");
    fo = fopen("out/test1.out", "w");
    fo2 = fopen("test_times/sparse_time", "w");
    fprintf(fo, "SPARSE\n\n");
    int n, x, m, l, r;
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test2
    v = realloc(v, 4*MAX);
    fi = fopen("in/test2.in", "r");
    fo = fopen("out/test2.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test3
    v = realloc(v, 4*MAX);
    fi = fopen("in/test3.in", "r");
    fo = fopen("out/test3.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test4
    v = realloc(v, 4*MAX);
    fi = fopen("in/test4.in", "r");
    fo = fopen("out/test4.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test5
    v = realloc(v, 4*MAX);
    fi = fopen("in/test5.in", "r");
    fo = fopen("out/test5.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test6
    v = realloc(v, 4*MAX);
    fi = fopen("in/test6.in", "r");
    fo = fopen("out/test6.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test7
    v = realloc(v, 4*MAX);
    fi = fopen("in/test7.in", "r");
    fo = fopen("out/test7.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test8
    v = realloc(v, 4*MAX);
    fi = fopen("in/test8.in", "r");
    fo = fopen("out/test8.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test9
    v = realloc(v, 4*MAX);
    fi = fopen("in/test9.in", "r");
    fo = fopen("out/test9.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test10
    v = realloc(v, 4*MAX);
    fi = fopen("in/test10.in", "r");
    fo = fopen("out/test10.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test11
    v = realloc(v, 4*MAX);
    fi = fopen("in/test11.in", "r");
    fo = fopen("out/test11.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test12
    v = realloc(v, 4*MAX);
    fi = fopen("in/test12.in", "r");
    fo = fopen("out/test12.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    
    //Test13
    v = realloc(v, 4*MAX);
    fi = fopen("in/test13.in", "r");
    fo = fopen("out/test13.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test14
    v = realloc(v, 4*MAX);
    fi = fopen("in/test14.in", "r");
    fo = fopen("out/test14.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test15
    v = realloc(v, 4*MAX);
    fi = fopen("in/test15.in", "r");
    fo = fopen("out/test15.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test16
    v = realloc(v, 4*MAX);
    fi = fopen("in/test16.in", "r");
    fo = fopen("out/test16.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test17
    v = realloc(v, 4*MAX);
    fi = fopen("in/test17.in", "r");
    fo = fopen("out/test17.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test18
    v = realloc(v, 4*MAX);
    fi = fopen("in/test18.in", "r");
    fo = fopen("out/test18.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;  
    fclose(fi);
    fclose(fo);

    //Test19
    v = realloc(v, 4*MAX);
    fi = fopen("in/test19.in", "r");
    fo = fopen("out/test19.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test20
    v = realloc(v, 4*MAX);
    fi = fopen("in/test20.in", "r");
    fo = fopen("out/test20.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test21
    v = realloc(v, 4*MAX);
    fi = fopen("in/test21.in", "r");
    fo = fopen("out/test21.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test22
    v = realloc(v, 4*MAX);
    fi = fopen("in/test22.in", "r");
    fo = fopen("out/test22.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);

    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        if(i==3){
            v[i] = 0;
            fillTable(v, n);
        }
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test23
    v = realloc(v, 4*MAX);
    fi = fopen("in/test23.in", "r");
    fo = fopen("out/test23.out", "w");
    fprintf(fo, "SPARSE\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    fillTable(v, n);

    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        if(i%100000==0){
            v[i] = 0;
            fillTable(v, n);
        }
        int query_answer = query(l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f", total_t);

    fclose(fi);
    fclose(fo);
    fclose(fo2);
    free(v);

    return 0;
}
