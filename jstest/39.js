// http://www.nowcoder.com/practice/0158a4f165154f2eaf27d1907aa55e57?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function iterate(obj) {
    var result = [];
    for (key in obj) {
        if (obj.hasOwnProperty(key))
            result.push(key + ": " + obj[key]);
    }
    return result;
}

// var C = function() {this.foo = 'bar'; this.baz = 'bim';}; C.prototype.bop = 'bip'; iterate(new C());
// ["foo: bar", "baz: bim"]
