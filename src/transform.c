unsigned char transform(char c)
{
    switch (c) {
        case '+': return 0x00;
        case '-': return 0x01;
        case '>': return 0x02;
        case '<': return 0x03;
        case '[': return 0x04;
        case ']': return 0x05;
        case '.': return 0x06;
        case ',': return 0x07;

        default: return 0xff;
    }
}
