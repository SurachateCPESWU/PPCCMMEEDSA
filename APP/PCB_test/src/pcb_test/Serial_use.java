/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pcb_test;

import com.fazecast.jSerialComm.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Serial_use {

    public static void main(String args[]) throws IOException, InterruptedException {
        SerialPort ports[] = SerialPort.getCommPorts();
        SerialPort port = ports[1];

        if (port.openPort()) {
            System.out.println("Port COM3 Opened");
        } else {
            System.out.println("Error Opening Port!!!");
        }
        port.setComPortTimeouts(SerialPort.TIMEOUT_READ_SEMI_BLOCKING, 0, 0);
        port.setBaudRate(9600);

        InputStream inputStream = port.getInputStream();
        final OutputStream outputStream = port.getOutputStream();

        String line = "";
        System.out.print(SerialPort.getCommPorts());
        while (true) {
            
            line = line + (Character.toString((char) inputStream.read()));
            if (line.contains("END")) {
                //remove END-er
                line = line.replace("END", "");
                System.out.println(line);
                line = "";
            }
            Thread.sleep(10);
        }

    }
}

