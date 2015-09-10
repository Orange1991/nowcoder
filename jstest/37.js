// http://www.nowcoder.com/practice/dfcc28bf243642b795eaf5a2a621acc5?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function alterContext(fn, obj) {
    return fn.call(obj);
}

// alterContext(function() {return this.greeting + ', ' + this.name + '!'; }, {name: 'Rebecca', greeting: 'Yo' })
// "Yo, Rebecca!"
