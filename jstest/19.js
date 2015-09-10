// http://www.nowcoder.com/practice/72c661d926494bd8a50608506915268c?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function count(start, end) {
    var cur = start;
    var timeId = undefined;
    var tick = function() {
        console.log(cur++);
        if (cur <= end) 
            timeId = setTimeout(tick, 100);
    };
    var counter = {
        cancel: function(){
            if (timeId !== undefined) clearTimeout(timeId);
        }
    };
    tick();
    return counter;
}
