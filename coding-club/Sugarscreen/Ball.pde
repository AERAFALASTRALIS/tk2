class Ball {
    // les objets créés avec cette class auront toutes ces "variables membres"
    PVector pos;
    int size;
    PVector speed;
    color random_color; // Bonus pour le visuel
   
    Ball(int _size) {
        pos = new PVector(width/2, height/2);
        size = _size;
        speed = new PVector(random(1, 6), random(1, 6));
        random_color = color(random(0, 255), random(0, 255), random(0, 255));
    }

    void stayIn() {
      if (pos.x <= (size / 2) || pos.x >= width - (size / 2))
        speed.x = speed.x * -1;
      if (pos.y <= (size / 2) || pos.y >= height - (size / 2))
        speed.y = speed.y * -1;
    }

    //display doit afficher un cercle aux coordonnées pos de taille size par size
    void display() {
      fill(random_color); //remplit le cercle en une couleur aléatoire
      pos.x = pos.x + speed.x;
      pos.y = pos.y + speed.y;
      ellipse(pos.x, pos.y, size, size);
    }
}
