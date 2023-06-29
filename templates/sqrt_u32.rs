fn sqrt_u32(x: u32) -> u32 {
    let mut x = x;
    let mut m: u32 = 1 << 30;
    let mut r: u32 = 0;
    let mut nr: u32;

    loop {
        nr = m + r;
        r >>= 1;
        if nr <= x {
            x -= nr;
            r += m;
        }
        m >>= 2;
        if m == 0 {
            break;
        }
    }

    r
}
