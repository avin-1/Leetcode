int findTheWinner(int n, int k) {
    bool *eliminated = malloc(n*sizeof(bool));
    memset(eliminated, 0, n*sizeof(bool));

    int remaining = n;
    int i = 0;

    while (remaining > 1) {
        int counter = 0;
        while (counter < k - 1) {
            i = (i + 1) % n;
            if (eliminated[i]!=1) {
                counter++;
            }
        }

        while (eliminated[i]==1) {
            i = (i + 1) % n;
        }
        eliminated[i] = 1;
        remaining--;

        while (eliminated[i]==1) {
            i = (i + 1) % n;
        }
    }

    int ans = -1;
    for (int i = 0; i <= n; i++) {
        if (eliminated[i]==0) {
            ans = i;
            break;
        }
    }

    return ans+1;
}