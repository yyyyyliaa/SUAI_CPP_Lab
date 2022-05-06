int func(int x){
    int w = 0;
    while (x>0){
        w+=x&1;
        x>>=1;
    }
    return w;
}
