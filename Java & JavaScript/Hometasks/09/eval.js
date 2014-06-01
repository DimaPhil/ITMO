var binaryOperation = function(f) {
    return function(a, b) {
        return function(x, y, z) {
            return f(a(x, y, z), b(x, y, z));
        }
    }
}

var unaryOperation = function(f) {
    return function(a) {
        return function(x, y, z) {
            return f(a(x, y, z));
        }
    }
}

var cnst = function(a) {
    return function(x, y, z) {
        return a;
    }
}

var abs = unaryOperation(function(a) { return Math.abs(a); } )
var log = unaryOperation(function(a) { return Math.log(a); } )
                                  
var subtract = binaryOperation(function(a, b) { return a - b; } );
var add = binaryOperation(function(a, b) { return a + b; } );
var multiply = binaryOperation(function(a, b) { return a * b; } );
var divide = binaryOperation(function(a, b) { return a / b; } );

var variable = function(name) {
    return function(x, y, z) {
        if (name == "x") {
            return x;
        }
        if (name == "y") {
            return y;
        }
        if (name == "z") {
            return z;
        }
    }                 
}

function isVariable(c) {
    return (c == 'x' || c == 'y' || c == 'z');
}

function isNumber(s) {
    return ('0' <= s[0] && s[0] <= '9');
}

function isUnaryOperation(s) {
    return (s == 'abs' || s == 'log'); 
}

function parse(s) {
    var tokens = s.match(/-d+|\d+|\d+|abs|log|-|[xyz+*/]/g)
    stack = [];
    h = 0;
    for (var i = 0; i < tokens.length; i++) {
        if (isVariable(tokens[i])) {
            stack[h++] = variable(tokens[i]);
        } else if (isNumber(tokens[i])) {
            stack[h++] = cnst(Number(tokens[i]));
        } else if (isUnaryOperation(tokens[i])) {
            var f = stack[h - 1];
            h--;
            if (tokens[i] == 'abs') {
                stack[h++] = abs(f);
            }  
            if (tokens[i] == 'log') {
                stack[h++] = log(f);
            }
        } else {
            var f = stack[h - 2];
            var g = stack[h - 1];
            h -= 2;
            if (tokens[i] == '-') {
                stack[h++] = subtract(f, g);
            }
            if (tokens[i] == '+') {
                stack[h++] = add(f, g);
            }
            if (tokens[i] == '*') {
                stack[h++] = multiply(f, g);
            }
            if (tokens[i] == '/') {
                stack[h++] = divide(f, g);
            }
        }
    }
    return stack[0];
}

println(parse("xx2-*x*1+")(5, 5, 5));