/// <reference path="./nodelib/node.js">
var dgram = require('dgram');
var server = dgram.createSocket('udp4');

console.log("Socket created\n");

var players = []; // players;

server.on("message", function (message, information) {
    var params = message.toString().split(" ");

    switch (params[0]) { // 0th term is command
        case "join":
            var currentPlayer = new Player(parseInt(params[1]), parseInt(params[2]));

            players.push(currentPlayer);

            var message = players.indexOf(currentPlayer).toString(10);
            var response = new Buffer(message.length);
            response.write(message);

            server.send(response, 0, response.length, information.port, information.address, function (error, sent) {
                if (error) {
                    console.log("ERROR: could not send login response");
                }
                else {
                    console.log("SUCCESS: sent login data to " + information.address + ":" + information.port);
                }
            });

            break;

        case "move":
            var id = parseInt(params[1], 10);

            var x = parseInt(params[2], 10);
            var y = parseInt(params[3], 10);

            players[id].x = x;
            players[id].y = y;

            console.log("INFO: Data received from player " + id + " move to " + x + " " + y);

            break;
    }
});

server.bind(9000);

function Player(x, y) {
    this.x = x || 0;
    this.y = y || 0;
}