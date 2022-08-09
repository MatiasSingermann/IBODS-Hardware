#include <ESP8266WiFiMulti.h>


  WiFiServer servidor (80);
  
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
}

void loop() {

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
  
prepareHtmlPage();

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
