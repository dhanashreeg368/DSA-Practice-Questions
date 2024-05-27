/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

var createCounter = function(init) {
    var presentCount = init;
    function increment() {
        return ++presentCount;
    }
    function decrement() {
        return --presentCount;
    }
    function reset() {
        return (presentCount = init);
    }
    return {increment: increment, reset: reset, decrement: decrement};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */