#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_VALUE 1000000

int min(int x, int y){
    if(x < y) return x;
    return y;
}

void update(int index, int value, int n,int min_block[],int arr[]){
    
    //se schimba un element din vector
    int blocksize = ceil(sqrt(n)); 
    int block_nr = index / blocksize; 
    min_block[block_nr]=min(value,min_block[block_nr]);
    arr[index] = value; 
} 

int query(int l, int r, int n, int min_block[], int arr[]){ 
 
    int min_in_range = 2147483647;
    int blocksize = ceil(sqrt(n)); 
    
    while (l<r && l%blocksize!=0 && l!=0) {
     
        // primul bloc din query
        if(arr[l] < min_in_range){
            min_in_range=arr[l];
        }
        l++; 
    } 
    while (l+blocksize <= r){ 
     
        if(min_block[l/blocksize] < min_in_range){
            min_in_range = min_block[l/blocksize];
        }
        l += blocksize; 
    } 
    while (l <= r){ 
     
        // ultimul bloc din query
        if(arr[l]<min_in_range){
            min_in_range=arr[l];
        }
        l++; 
    } 
    //se returneaza minimul dintre toate blocurile
    return min_in_range; 
} 


void Build(int input[], int n,int arr[],int min_block[]) {
 
    int block_nr = -1;  
    int blocksize = ceil(sqrt(n)); 

    for (int i=0; i<n; i++){ 
     
        arr[i] = input[i]; 
        if (i % blocksize==0){ 
         
            //trecem la urmatorul bloc
            block_nr++; 
            min_block[block_nr]=arr[i];
        } 
        //minimul din blocul curent
        min_block[block_nr]=min(min_block[block_nr],arr[i]); 
    }
} 

int main(){

    FILE *fi;
    FILE *fo;
    FILE *fo2; 
    float start_t, end_t, total_t=0.0;

    //Test1       
    fi = fopen("in/test1.in", "r");
    fo = fopen("out/test1.out", "w");
    fo2 = fopen("test_times/sqrt_time", "w");

    int *v = calloc(4, MAX_VALUE);
    int *arr = calloc(4, MAX_VALUE);
    int *min_block = calloc(4, MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    int n, x, m, l, r;
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr,min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test2       
    fi = fopen("in/test2.in", "r");
    fo = fopen("out/test2.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test3       
    fi = fopen("in/test3.in", "r");
    fo = fopen("out/test3.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test4       
    fi = fopen("in/test4.in", "r");
    fo = fopen("out/test4.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test5       
    fi = fopen("in/test5.in", "r");
    fo = fopen("out/test5.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test6       
    fi = fopen("in/test6.in", "r");
    fo = fopen("out/test6.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test7
    fi = fopen("in/test7.in", "r");
    fo = fopen("out/test7.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test8       
    fi = fopen("in/test8.in", "r");
    fo = fopen("out/test8.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test9       
    fi = fopen("in/test9.in", "r");
    fo = fopen("out/test9.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test10       
    fi = fopen("in/test10.in", "r");
    fo = fopen("out/test10.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test11       
    fi = fopen("in/test11.in", "r");
    fo = fopen("out/test11.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test12       
    fi = fopen("in/test12.in", "r");
    fo = fopen("out/test12.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test13       
    fi = fopen("in/test13.in", "r");
    fo = fopen("out/test13.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test14      
    fi = fopen("in/test14.in", "r");
    fo = fopen("out/test14.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test15       
    fi = fopen("in/test15.in", "r");
    fo = fopen("out/test15.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test16       
    fi = fopen("in/test16.in", "r");
    fo = fopen("out/test16.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test17       
    fi = fopen("in/test17.in", "r");
    fo = fopen("out/test17.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test18
    fi = fopen("in/test18.in", "r");
    fo = fopen("out/test18.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test19       
    fi = fopen("in/test19.in", "r");
    fo = fopen("out/test19.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test20       
    fi = fopen("in/test20.in", "r");
    fo = fopen("out/test20.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test21       
    fi = fopen("in/test21.in", "r");
    fo = fopen("out/test21.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test22       
    fi = fopen("in/test22.in", "r");
    fo = fopen("out/test22.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        if(i==3){
            update(i, 0, n, min_block, arr);
        }
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);

    //Test23       
    fi = fopen("in/test23.in", "r");
    fo = fopen("out/test23.out", "w");

    v = realloc(v, 4*MAX_VALUE);
    arr = realloc(arr, 4*MAX_VALUE);
    min_block = realloc(min_block, 4*MAX_VALUE);
    fprintf(fo, "SQRT\n\n");
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    Build(v, n, arr, min_block); 
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        update(i, 0, n, min_block, arr);
        int query_answer = query(l, r, n, min_block, arr);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f", total_t);
    total_t=0.0;

    fclose(fi);
    fclose(fo);
    fclose(fo2);
    free(v);
    free(min_block);
    free(arr);
    
    return 0;
}
