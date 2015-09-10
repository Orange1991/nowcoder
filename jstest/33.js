// http://www.nowcoder.com/practice/2c7f25d532aa4e20b67af9d3c93dc65f?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function valueAtBit(num, bit) {
    num >>= bit - 1;
    return num & 0x1;
}

// valueAtBit(128, 8) = 1
