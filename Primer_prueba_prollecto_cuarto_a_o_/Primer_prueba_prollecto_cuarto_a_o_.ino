#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>

  WiFiServer servidor (80);}
  char server[] = //Preguntarle a IVO que url poner acá o si deberíanmos comprar una. 
  
void setup() {
  
  Serial.begin(115200);
  Serial.println();
  pinMode (2, OUTPUT);

  WiFi.begin("Galaxy S20b3f0", "arfy7595");

  Serial.println ("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  { 
      delay (500);
      Serial.print (".");
  }
  Serial.println ("");

  Serial.println ("Connection stablished!!");
 
  //Server part

  servidor.begin(); 

   Serial.print (WiFi.localIP());

  //client                          ver si uso cliente o servidor con IVOOOO

    if (client.connect(server, 80)) {
      // acá va el request de HTML para pedir los datos al servidor web 

    client.println("GET /search?q=arduino HTTP/1.1");

    client.println("Host: //nombre de la pagina");

    client.println("Connection: close");

    client.println();
    }
}

void loop() {

    listNetworks();

 while (client.available()) {

    char c = client.read();

    Serial.write(c);

  }

  // if the server's disconnected, stop the client:

  if (!client.connected()) {

    Serial.println();

    Serial.println("disconnecting from server.");

    client.stop();

     // do nothing forevermore:

    while (true);

  }
}
    
    WiFiClient client = servidor.available();

  if (client)
  {
        while(!client.available()&&client.connected())
    {
    delay(1);
    }

  String Command = client.readStringUntil('r');

  if (Command.indexOf("LED=ON") > 0)
  {
      digitalWrite(2,HIGH);
  }
  if (Command.indexOf("LED=OFF") > 0)
  {
      digitalWrite(2,LOW);
  }
    client.flush(); 
  }
  

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");// La conexión se cierra después de finalizar de la respuesta
    client.println();
    //Pagina html  para en el navegador
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title>Naylam Mechatronics</title>");
    client.println("<body>");
    client.println("<h1 align='center'>Test ESP8266</h1>");
    client.println("<div style='text-align:center;'>");
    client.println("<br />");            
    client.println("<button onClick=location.href='./?LED=ON'>LED ON</button>");           
    client.println("<button onClick=location.href='./?LED=OFF'>LED OFF</button>");
    client.println("<br />");
    client.println("</div>");
    client.println("</body>");
    client.println("</html>");


}

void listNetworks() {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);
  
  String ArrayNetWorks[20];
 
  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    ArrayNetWorks[thisNet] = String(WiFi.SSID);
  }
}

//String prepareHtmlPage()
//{
//  String htmlPage;
//  htmlPage.reserve(1024);               // prevent ram fragmentation
//  htmlPage = F ("HTTP/1.1 200 OK\r\n"
//               "Content-Type: text/html\r\n"
//               "Connection: close\r\n"
//               "<!DOCTYPE HTML>"
//               "<html>"
//               "<head><title>Naylam Mechatronics</title>"
//               "<body>"
//               "<h1 align='center'>Test ESP8266</h1>"
//               "<div style='text-align:center;'>"
//               "<br />"
//               "<button onClick=location.href='./?LED=ON'>LED ON</button>"
//               "<button onClick=location.href='./?LED=OFF'>LED OFF</button>"
//               "<br />"
//               "</div>"
//               "</body>"
//               "<html>");
// return htmlPage;
//}
//  
