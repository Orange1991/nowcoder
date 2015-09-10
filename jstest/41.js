// http://www.nowcoder.com/practice/5ef31f11adf64d9fb18d74860e9ab873?rp=3&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function containsRepeatingLetter(str) {
    return /([a-zA-Z])\1/.test(str);
}

// containsRepeatingLetter('rattler') -> true
