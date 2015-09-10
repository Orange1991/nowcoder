// http://www.nowcoder.com/practice/7b74386695cc48349af37196f45e62a8?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function convertToBinary(num) {
    var b = num.toString(2);
    var prefix = '';
    if (b.length % 8 != 0) {
        var len = 8 - b.length % 8;
        for (var i = 0; i < len; ++i)
            prefix += '0';
    }
    return prefix + b;
}

// convertToBinary(65) = "01000001"
