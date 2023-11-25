#include <CTBot.h>

CTBot myBot;

const char ssid[] PROGMEM = "Redmi";
const char password[] PROGMEM = "pashter1922";
const char token[] PROGMEM = "6885549233:AAGQo_7C-l9H4pqWJb7CuND3XYlEKXXlQVg";

String data;
char c;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");
  myBot.wifiConnect(ssid, password);
  myBot.setTelegramToken(token);
  if (myBot.testConnection())
  {
    Serial.println("Jaringan WiFi Terhubung");
  }
  else
  {
    Serial.println("Jaringan WiFi Terputus");
  }
}

void loop() {
  TBMessage msg;

  if (myBot.getNewMessage(msg)) {
    if (msg.text.equalsIgnoreCase("/cek_ketinggian")) {
      Serial.print("/cek_ketinggian");           
      myBot.sendMessage(msg.sender.id, "⌛️ Mengukur Ketinggian...");  //kirim pesan ke bot telegram
    }
    else if (msg.text.equalsIgnoreCase("/help")) {        
      String helpMessage = "Haiii " + msg.sender.username + " 😁\n\nGunakan Perintah Dibawah Ini 👇🏻:\n/cek_ketinggian - Pengecekan Jarak Ketinggian Air\n/ping - Test Ping\n/help - Bantuan";
      //Serial.println("help");
      myBot.sendMessage(msg.sender.id, helpMessage);
    }
    else if (msg.text.equalsIgnoreCase("/ping")) {
      myBot.sendMessage(msg.sender.id, "PONG 🏓");;
    }
    else {                                                    
      // membalas pesan selain kode diatas
      String reply;
      reply = "Gunaka Command: /help Untuk Bantuan";
      myBot.sendMessage(msg.sender.id, reply);         
    }
  }
  
  while(Serial.available()>0){
    delay(10);
    c = Serial.read();
    data += c;
    data.trim()
  }
  if (data.length()>0) {
    Serial.println(data);
    if (data == "Awas")
    {
      myBot.sendMessage(msg.sender.id, "⚠️ Awas Banjir: Ketinggian Air Melebihi 3,5 Meter");
      delay(10);
    }
    else if (data == "Siaga")
    {
      myBot.sendMessage(msg.sender.id, "⚠️ Siaga Banjir: Ketinggian Air Melebihi 2 Meter");
      delay(10);
    }
    else
    {
      myBot.sendMessage(msg.sender.id, "📝 Hasil Pengukuran\n\nJarak Ketinggian Air Ke Permukaan Adalah : " + data + "cm");
      delay(10);
    }
    data = "";
  }
  delay(500);
}