bool RisRed(float red,float green,float blue){
  if (red>21-tole && red<21+tole &&
      green>54.5-tole && green <54.5+tole &&
      blue>39.5-tole && blue <39.5+tole) {
        return true;
  }
}

bool RisGreen(float red,float green,float blue){
  if (red>50.5-tole && red<50.5+tole &&
      green>36-tole && green <36+tole &&
      blue>36-tole && blue <36+tole) {
        return true;
  }
}

bool RisBlue(float red,float green,float blue){
  if (red>56.5-tole && red<56.5+tole &&
      green>47.5-tole && green <47.5+tole &&
      blue>30.5-tole && blue <30.5+tole) {
        return true;
  }
}

bool RisClear(float red,float green,float blue){
  if (red>61-tole && red<61+tole &&
      green>72-tole && green <72+tole &&
      blue>56-tole && blue <56+tole) {
        return true;
  }
}

bool LisRed(float red,float green,float blue){
  if (red>22-tole && red<22+tole &&
      green>48.5-tole && green <48.5+tole &&
      blue>37.5-tole && blue <37.5+tole) {
        return true;
  }
}

bool LisGreen(float red,float green,float blue){
  if (red>51.5-tole && red<51.5+tole &&
      green>19.5-tole && green <19.5+tole &&
      blue>37.5-tole && blue <37.5+tole) {
        return true;
  }
}

bool LisBlue(float red,float green,float blue){
  if (red>55.5-tole && red<55.5+tole &&
      green>50-tole && green <50+tole &&
      blue>30-tole && blue <30+tole) {
        return true;
  }
}

bool LisClear(float red,float green,float blue){
  if (red>53.5-tole && red<53.5+tole &&
      green>61.5-tole && green <61.5+tole &&
      blue>48.5-tole && blue <48.5+tole) {
        return true;
  }
}
