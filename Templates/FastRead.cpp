LL read() {
    LL num = 0, F = 1; char c = ' ';
    while (c < '0' || c > '9') F = (c == '-') ? -1 : 1, c = getchar();
    while (c >= '0' && c <= '9') num = (num << 1) + (num << 3) + c - '0', c = getchar();
    return num * F;
}
