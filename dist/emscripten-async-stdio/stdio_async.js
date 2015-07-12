// set up terminal
var pre = document.getElementById('term');
var term = new Terminal({rows: 20, columns: 80});
pre.tabindex = 0;
var stream = term.dom(pre);

// create input buffer
var fifo = {
    // set to true when there is a complete line for fgets to get
    line: false,
    // array of characters in buffer
    data: [],
    // written to char by char by the terminal input
    write: function(elem) {
        // TODO handle backspace
        elem = elem.toString();
        if (elem === '\r') {
            this.line = true;
            term.write('\r\n');
            this.data.push('\n');
        } else {
            this.data.push(elem);
        }
        term.write(elem);
    },
    // placeholders for pipe functions
    on: function() {console.log('on:', arguments);},
    emit: function() {console.log('emit:', arguments);},
    once: function() {console.log('once:', arguments);}
};
stream.pipe(fifo);

var Module = {
    // called by puts, printf etc.
    // TODO: create a non-buffered output
    print: function (text) {
        term.write(text + '\r\n');
    },
    preRun: function () {
        // called by getchar, fgets etc.
        FS.init(function () {
            var a = fifo.data.shift();
            if (a)
                return a.charCodeAt(0);
            return null;
        });
    }
};
