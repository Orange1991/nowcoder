// http://www.nowcoder.com/practice/48e53feaabe94506a61300edadb5496d?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function createModule(str1, str2) {
    var obj = {};
    obj.greeting = str1;
    obj.name = str2;
    obj.sayIt = function() {
        return obj.greeting + ', ' + obj.name;
    };
    return obj;
}

// createModule('Hello', 'Orange').sayIt(); // -> "Hello, Orange"
