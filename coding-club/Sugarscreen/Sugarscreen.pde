Ball balls[] = new Ball[100];

void setup() {
    size(600, 600); //définit la taille de la fenêtre
    background(100); //définit la couleur de fond de la fenêtre, 100 = gris
    for(int i = 0;  i < balls.length; i++) {
       balls[i] = new Ball(int(random(20, 60)));
    }
}

void draw(){
    background(100);
    for(int i = 0; i < balls.length; i++) {
        balls[i].display();
        balls[i].stayIn();
    };
}
