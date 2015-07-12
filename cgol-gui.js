var ROWS = 25;
var COLS = 25;
var CELL_SIZE = 18;
var CELL_PAD = 1; // applied to each side of a cell, hence doubled
var CELL_GRID_SIZE = CELL_SIZE + (2 * CELL_PAD);
var RUN_DELAY = 250;

var grid; // pointer to the grid
var canvas = document.getElementById('cgol-canvas');
var ctx = canvas.getContext('2d');
var cWidth = canvas.width;
var cHeight = canvas.height;
var running = false;

function drawGrid() {
    ctx.clearRect(0, 0, cWidth, cHeight);
    for (var r = 0; r < ROWS; ++r) {
        for (var c = 0; c < COLS; ++c) {
            if (Module._grid_get_at(grid, r, c) == 1) {
                var x = CELL_GRID_SIZE * c + CELL_PAD;
                var y = CELL_GRID_SIZE * r + CELL_PAD;
                ctx.fillRect(x, y, CELL_SIZE, CELL_SIZE);
            }
        }
    }
}

canvas.onclick = function (ev) {
    // get the mouse location within the canvas
    var rect = canvas.getBoundingClientRect();
    var x = ev.clientX - rect.left;
    var y = ev.clientY - rect.top;

    var cellX = Math.floor(x/CELL_GRID_SIZE);
    var cellY = Math.floor(y/CELL_GRID_SIZE);
    Module._golutil_toggle(grid, cellY, cellX);
    drawGrid();
};

document.getElementById('step-btn').onclick = function () {
    Module._golutil_cycle(grid);
    drawGrid();
};

document.getElementById('run-btn').onclick = function () {
    if (running) {
        running = false;
        document.getElementById('run-btn').innerHTML = 'Run';
    } else {
        running = true;
        document.getElementById('run-btn').innerHTML = 'Stop';
        runLoop();
    }
};

function runLoop () {
    if (!running) return;
    Module._golutil_cycle(grid);
    drawGrid();
    setTimeout(runLoop, RUN_DELAY);
}

document.getElementById('randomize-btn').onclick = function () {
        Module._golutil_randomize(grid);
        drawGrid();
};

document.getElementById('clear-btn').onclick = function () {
        Module._grid_clear(grid);
        drawGrid();
};

Module._main = function() {
    grid = Module._grid_create(ROWS, COLS);
    Module._golutil_randomize(grid);
    drawGrid();
};
