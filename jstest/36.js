// http://www.nowcoder.com/practice/6429776e4630435cbc3eeb36bdf41f83?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function multiply(a, b) {
    var result = (a * b).toString();
    var indexA = a.toString().indexOf('.');
    var indexB = b.toString().indexOf('.');
    var len = 0;
    if (indexA != -1) 
        len += a.toString().length - indexA - 1;
    if (indexB != -1) 
        len += b.toString().length - indexB - 1;
    return result.substring(0, result.indexOf('.') + len + 1);
}

// multiply(3, 0.0001) = "0.0003"
