/*
*  Comunicación Serial Unity + Arduino Uno
*  basado en el tutorial de Jhimmy Astoraque Durán
*/


using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class Serial : MonoBehaviour
{
    SerialPort arduinoPort = new SerialPort("/dev/ttyACM0");

    private void Awake()
    {
        arduinoPort.BaudRate =9600;
        arduinoPort.Parity = Parity.None;
        arduinoPort.StopBits = StopBits.One;
        arduinoPort.DataBits = 8;
        arduinoPort.Handshake = Handshake.None;     
    }

    // Start is called before the first frame update
    void Start()
    {
        arduinoPort.Open();
        
    }

    public void SendMessageToArduino( string msg)
    {
        arduinoPort.WriteLine(msg);
    }

    public void ClosePort()
    {
        arduinoPort.Close();
    }
}
