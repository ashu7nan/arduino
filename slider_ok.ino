#include<ESP8266WiFi.h>
const char* ssid ="Abhijeet";
const char* password="abhijeet";
int value=HIGH;
//To give the port number
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  //Connect to wifi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() !=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  //Start the server
  server.begin();//Doubt
  Serial.println("Server started");

  //Print the IP Adress
  Serial.print("Use this URL to connect:");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  pinMode(D4,OUTPUT);
  digitalWrite(D4,value);
  }

void loop() {
  // put your main code here, to run repeatedly:
  //Check if a client is connected 
  WiFiClient client =server.available();
  if(!client)
  {
    return;
  }
  //Wait until the client sends some data
  Serial.println("new client");
  while(!client.available())
{
  delay(1);
}
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  if(request.indexOf("led")!=-1)
 {
  int i=request.indexOf("led");
  int j=request.indexOf("HTTP");
  String ch=request.substring(i+3,j-1);
  value=ch.toInt();
  Serial.println(value,DEC);
   analogWrite(D4,LOW);
   // value=LOW;
 }

client.println("HTTP/1.1 200 OK");
client.println("Connect-Type:text/html");
client.println("");//do not forget
client.println("<!DOCTYPE HTML>");
client.println("<html><body>");
//if(value==LOW)
//{
//  client.print("<font color='green'>ON<font>");
//}
//else
//{
//  client.print("<font color='red'>OFF<font>");
//}
client.print("<br><br>");
client.print("<html><head><script>slide(){document.getElementById('link').href='led'+document.getElementById('slide').value}</script></head>");
client.print("<body><a id='link'><input type='range' id='slide' onchange='slide()' min='0' max='1023'><\a></body></html>");
delay(1);

  

}
