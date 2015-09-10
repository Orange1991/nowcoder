// http://www.nowcoder.com/practice/4f7d25a30eb1463cbf1daac39ec04f8d?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function alterObjects(constructor, greeting) {
    constructor.prototype.greeting = greeting;
}

// var C = function(name) {this.name = name; return this;}; var obj1 = new C('Rebecca'); alterObjects(C, 'What\'s up'); obj1.greeting;
// "What's up"
