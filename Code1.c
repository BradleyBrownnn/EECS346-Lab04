check_score_combos(int total_score){
    int td_2pt, td_extrapt, td, fg, safety;
    for(td_2pt = 0; td_2pt*8<=total_score; td_2pt++){
        for(td_extrapt = 0; td_extrapt*7<= total_score; td_extrapt++){
            for(td = 0; td*6<=total_score; td++){
                for(fg=0; fg*3<= total_score;fg++){
                    for(safety=0;safety*2<=total_score; safety++) {
                        if(td_2pt*8 + td_extrapt*7 + td*6 + fg*3 + safety*2 == total_score){
                            printf("%d Touch Down W/ 2 pts ,%dTouch Down W/ Extra Point, %d Touch Down, %d Feild Goal, %d Safety\n", td_2pt, td_extrapt, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}   
int main() {
    int total_score;

    while(1){
        print("to exit enter 0 or 1");
        print("Enter the score of the game: ");
        scan("%d", &total_score);

        if(total_score<=1){
            break;
        }

        check_score_combos(total_score);

    }

    

}