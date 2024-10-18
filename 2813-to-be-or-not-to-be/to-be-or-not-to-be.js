/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe(valu){if(val===valu){return true;}
               throw("Not Equal");},
        notToBe(valu){ if(val!==valu){return true;} throw("Equal");}
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */