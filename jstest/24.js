// http://www.nowcoder.com/practice/578026cd24e3446bbf27fe565473dc26?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function makeClosures(arr, fn) {
    var result = [];
    var f = function(index) {
        return function(){
            return fn(arr[index]);
        };
    };
    for (var i = 0; i < arr.length; ++i) {
        result[i] = f(i);
    }
    return result;
}

// var arr = [1, 2, 3]; 
// var square = function (x) { return x * x; }; 
// var funcs = makeClosures(arr, square); funcs[1]();
