// http://www.nowcoder.com/practice/8a7bff7ab0d345d5ac5c82e41d9f7115?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function fizzBuzz(num) {
    if (isNaN(num)) return false;
    var mod3 = num % 3;
    var mod5 = num % 5;
    if (mod3 == 0 && mod5 == 0) return 'fizzbuzz';
    if (mod3 == 0) return 'fizz';
    if (mod5 == 0) return 'buzz';
    return num;
}
