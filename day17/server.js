/**
 * Created by KICT-12 on 2016-07-19.
 */

const net = require('net');
const PORT = 8080;

net.createServer((socket)=> {

    console.log('connect :' + socket.remoteAddress +':'
        + socket.remotePort
    );

    socket.on('error',(evt)=>{
        console.log(evt);
    });
    socket.on('close',(evt)=>{
        console.log('connection closed!');
        console.log(evt);
    });
    socket.on('data',(evt)=>{
        //2byte : header(1004)
        //2byte : 요청 type
        //extra :...
        data = evt;

        let header = data.readInt16LE(0);
        let req_type = data.readInt16LE(2);

        console.log('header :' + header);
        console.log('request type :' + req_type);

    });

}).listen(PORT);

console.log('server listen :' + PORT);
