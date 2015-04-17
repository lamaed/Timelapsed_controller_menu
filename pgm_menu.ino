

void menu(int menu_num) {
  // put your setup code here, to run once:
if (menu_num == 0 || menu_num == 1)                   // Temporizador entre disparos
  {  
    lcd.setCursor (0,0);
    lcd.print("Temporizador ");
    lcd.setCursor (0,1);
    lcd.print("Tiempo: ");
    lcd.print (time_lapse_m);
    lcd.print ("m ");
    lcd.print (time_lapse_s);
    lcd.print ("s ");
    if (menu_num == 0)
      {
        lcd.setCursor (13,0);    
        lcd.print ("(m)");
      }
    if (menu_num == 1)
      {
        lcd.setCursor (13,0);    
        lcd.print ("(s)");
      }
  }
  else if (menu_num == 2) // Avance del carro por disparo
  {  
    //lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("Desplaza en mm");
    lcd.setCursor (0,1);
    lcd.print("Avance: ");
    lcd.print (avance_x);
    lcd.print("    ");
    
  }
  
    else if (menu_num >= 3 && menu_num <= 5) //selector número disparos
  {  
    //lcd.clear();
    lcd.setCursor (0,0);
    if (menu_num == 3)
    {lcd.print("Numero      _");}
    else if (menu_num == 4)
    {lcd.print("Numero       _");}
    else if (menu_num == 5)
    {lcd.print("Numero        _");}
    lcd.setCursor (0,1);
    lcd.print("Fotogramas: ");
    lcd.print (disparos);
    lcd.print ("    ");
  }
  
    else if (menu_num == 6) //Control Giro
  {  
    //lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("Rotacion");
    lcd.setCursor (0,1);
    lcd.print("Pasos: ");
    lcd.print (giro);
    lcd.setCursor (0,1);
  }
      else if (menu_num == 7) //Configuracion
  {  
    //lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("Configuracion");
    lcd.setCursor (0,1);
    lcd.print("volver  -  entrar");
    lcd.setCursor (0,1);
  }
  
  
  else if (menu_num == 11) //Avance manual del carro
  {  
    lcd.setCursor (0,0);
    lcd.print("Mover Slider   ");
    lcd.setCursor (0,1);
    lcd.print("- IZDA || DCHA +");
    lcd.setCursor (0,1);
  }
  
    else if (menu_num == 12) //giro manual
  {  
    lcd.setCursor (0,0);
    lcd.print("giro manual");
    lcd.setCursor (0,1);
    lcd.print("Pulse UP");
  }  
    else if (menu_num == 13) //DISPARO MANUAL CAMARA
  {  
    lcd.setCursor (0,0);
    lcd.print("Disparo manual");
    lcd.setCursor (0,1);
    lcd.print("Pulse UP");
  }
  
      else if (menu_num == 14) //retroiluminacion panel
  {  
    lcd.setCursor (0,0);
    lcd.print("Iluminacion");
    lcd.setCursor (0,1);
    lcd.print("pantalla: ");
    lcd.print(fadeValue);
    lcd.print("   ");
  }
}

