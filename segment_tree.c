#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#define MAX_VALUE 1000000

int min(int x, int y){
    if(x < y) return x;
    return y;
}

int middle(int l, int r){
    return l+(r-l)/2;
}

void update(int arr[], int* st, int sl, int sr,
                 int index, int value, int node)
{
    //daca s a gasit nodul
    if (sl == sr)
    {  
        arr[index] = value;
        st[node] = value;
    }
    //se cauta nodul
    else {
            int mid =middle(sl, sr);
             
            if (index >= sl && index <= mid)
                update(arr, st,
                            sl, mid, index,
                            value, 2 * node + 1);
            else
                update(arr,
                            st, mid + 1, sr,
                            index,
                            value, 2 * node + 2);
             
            st[node] = min(st[2 * node + 1],
                       st[2 * node + 2]);
    }
    return;
}

int make_st_helper(int v[], int sl, int sr, int *st, int si){

    int mid;

    //doar 1 element
    if (sl == sr){
        st[si] = v[sl];
        return v[sl];
    }
    
    //se calculeaza mijlocul si se apeleaza recursiv pe fiecare ramura
    //se pastreaza minimul celor 2 jumatati
    mid = middle(sl, sr);
    st[si] =  min(make_st_helper(v, sl, mid, st, si*2+1),
                     make_st_helper(v, mid+1, sr, st, si*2+2));
    return st[si];
}

int *make_st(int v[], int n){

    int x, max_size;
    int *st;
    
    //se afla inaltimea tree-ului si nr maxim de noduri
    x = (int)(ceil(log2(n)));
    max_size = 2*(int)pow(2, x) - 1;
    st = calloc(4, max_size);
 
    //incepe cu r=0 si l=n-1, dupa care o ia pe jumatati
    make_st_helper(v, 0, n-1, st, 0);
 
    return st;
}

int RMQ_helper(int *st, int sl, int sr, int ql, int qr, int index){

    int mid;

    // segmentul e in query
    if (ql <= sl && qr >= sr)
        return st[index];
 
    // segmentul dat nu e in query
    if (ql > sr || qr < sl)
        return 2147483647;
 
    // segmentul face overlap cu query
    mid = middle(sl, sr);
    return min(RMQ_helper(st, sl, mid, ql, qr, 2*index+1),
                  RMQ_helper(st, mid+1, sr, ql, qr, 2*index+2));
}

int RMQ(int *st, int n, int ql, int qr){

    // Verifica daca informatia citita din input file este corecta.
    if (ql < 0 || qr > n-1 || ql > qr)
    {
        printf("Input error - check input file values again.");
        return -1;
    }
 
    return RMQ_helper(st, 0, n-1, ql, qr, 0);
}

int main(){

    FILE *fi;
    FILE *fo;
    FILE *fo2;

    float start_t, end_t, total_t=0.0; 

    //Test1        
    fi = fopen("in/test1.in", "r");
    fo = fopen("out/test1.out", "w");
    fo2 = fopen("test_times/segtree_time", "w");
    fprintf(fo, "SEGTREE\n\n");
    int *v = calloc(4, MAX_VALUE);
    int n, x, m, l, r;
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    int *st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test2        
    fi = fopen("in/test2.in", "r");
    fo = fopen("out/test2.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test3        
    fi = fopen("in/test3.in", "r");
    fo = fopen("out/test3.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test4        
    fi = fopen("in/test4.in", "r");
    fo = fopen("out/test4.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test5        
    fi = fopen("in/test5.in", "r");
    fo = fopen("out/test5.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test6        
    fi = fopen("in/test6.in", "r");
    fo = fopen("out/test6.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test7        
    fi = fopen("in/test7.in", "r");
    fo = fopen("out/test7.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test8        
    fi = fopen("in/test8.in", "r");
    fo = fopen("out/test8.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test9        
    fi = fopen("in/test9.in", "r");
    fo = fopen("out/test9.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test10       
    fi = fopen("in/test10.in", "r");
    fo = fopen("out/test10.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test11        
    fi = fopen("in/test11.in", "r");
    fo = fopen("out/test11.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test12        
    fi = fopen("in/test12.in", "r");
    fo = fopen("out/test12.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test13        
    fi = fopen("in/test13.in", "r");
    fo = fopen("out/test13.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test14        
    fi = fopen("in/test14.in", "r");
    fo = fopen("out/test14.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test15        
    fi = fopen("in/test15.in", "r");
    fo = fopen("out/test15.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test16        
    fi = fopen("in/test16.in", "r");
    fo = fopen("out/test16.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test17        
    fi = fopen("in/test17.in", "r");
    fo = fopen("out/test17.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test18        
    fi = fopen("in/test18.in", "r");
    fo = fopen("out/test18.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test19        
    fi = fopen("in/test19.in", "r");
    fo = fopen("out/test19.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test20        
    fi = fopen("in/test20.in", "r");
    fo = fopen("out/test20.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test21        
    fi = fopen("in/test21.in", "r");
    fo = fopen("out/test21.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test22        
    fi = fopen("in/test22.in", "r");
    fo = fopen("out/test22.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        if(i==3){
            update(v, st, 0, n-1, i, 0, 0);
        }
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;
    fclose(fi);
    fclose(fo);
    free(st);

    //Test23       
    fi = fopen("in/test23.in", "r");
    fo = fopen("out/test23.out", "w");
    fprintf(fo, "SEGTREE\n\n");
    v = realloc(v, 4*MAX_VALUE);
    
    fscanf(fi, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        fscanf(fi, "%d", &x);
        v[i]=x;
    }
    st = make_st(v, n);
    
    for(int i=0; i<m; i++){
        fscanf(fi, "%d %d", &l, &r);
        start_t = clock();
        update(v, st, 0, n-1, i, 0, 0);
        int query_answer = RMQ(st, n, l, r);
        end_t = clock();
        total_t += (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fo, "%d\n", query_answer);
    }
    fprintf(fo2, "%f\n", total_t);
    total_t=0.0;

    fclose(fi);
    fclose(fo);
    fclose(fo2);
    free(v);
    free(st);

    return 0;
}
