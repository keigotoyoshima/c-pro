vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};


bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// keyを基準としてkey以上のindexを返す．左端を-1，右端をa.size()にしていることに注意
int binary_search(int key) {
    int ng = -1;
    int ok = a.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


// a[l] から a[r-1] までの中で初めて x 以上となるようなインデックスを返します。
lower_bound(a+l, a+r, x) - a
// vectorの場合
lower_bound(a.begin()+l, a.end()+r, x) - a.begin()

