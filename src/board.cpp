
#include <iostream>
#include "board.h"

territory::territory(int id, std::string name, int x, int y) : id(id), name(name), x(x), y(y){

}

territory::territory(){

}

void territory::addEdges(std::vector<territory> edges){
    for(territory edge : edges){
        this->edges.push_back(edge.id);
    }
}

board::board(){
    // North America
    territory alaska(0, "Alaska", 60, 90);
    territory northwest_territory(1, "Northwest Territory", 0, 0);
    territory greenland(2, "Greenland", 0, 0);
    territory alberta(3, "Alberta", 0, 0);
    territory ontario(4, "Ontario", 0, 0);
    territory quebec(5, "Quebec", 0, 0);
    territory western_united_states(6, "Western United States", 0, 0);
    territory eastern_united_states(7, "Eastern United States", 0, 0);
    territory central_america(8, "Central America", 0, 0);

    // South America
    territory venezuela(9, "Venezuela", 0, 0);
    territory peru(10, "Peru", 0, 0);
    territory argintina(11, "Argentina", 0, 0);
    territory brazil(12, "Brazil", 0, 0);

    // Africa
    territory north_africa(13, "North Africa", 0, 0);
    territory egypt(14, "Eqypt", 0, 0);
    territory east_africa(15, "East Africa", 0, 0);
    territory congo(16, "Congo", 0, 0);
    territory south_africa(17, "South Africa", 0, 0);
    territory madagascar(18, "Madagascar", 0, 0);

    // Austrialia
    territory indonesia(19, "Indonesia", 0, 0);
    territory new_guinea(20, "New Guinea", 0, 0);
    territory eastern_australia(21, "Eastern Australia", 0, 0);
    territory western_australia(22, "Western Australia", 0, 0);

    // Europe
    territory iceland(23, "Iceland", 0, 0);
    territory scandinavia(24, "Scandinavia", 0, 0);
    territory ukraine(25, "Ukraine", 0, 0);
    territory great_britan(26, "Great Britan", 0, 0);
    territory northern_europe(27, "Northern Europe", 0, 0);
    territory western_europe(28, "Western Europe", 0, 0);
    territory southern_europe(29, "Southern Europe", 0, 0);

    // Aisa
    territory ural(30, "Ural", 0, 0);
    territory siberia(31, "Siberia", 0, 0);
    territory yakutsk(32, "Yakutsk", 0, 0);
    territory kamchatka(33, "Kamchatka", 0, 0);
    territory irkutsk(34, "Irkutsk", 0, 0);
    territory mongolia(35, "Mongolia", 0, 0);
    territory japan(36, "Japan", 0, 0);
    territory afghanistan(37, "Afghanistan", 0, 0);
    territory china(38, "China", 0, 0);
    territory middle_east(39, "Middle East", 0, 0);
    territory india(40, "India", 0, 0);
    territory siam(41, "Siam", 0, 0);

    // North America
    alaska.addEdges(std::vector<territory>({kamchatka, northwest_territory, alberta}));
    territories[0] = alaska;
    
    northwest_territory.addEdges(std::vector<territory>({alaska, alberta, ontario, greenland}));
    territories[1] = northwest_territory;

    greenland.addEdges(std::vector<territory>({northwest_territory, ontario, quebec, iceland}));
    territories[2] = greenland;

    alberta.addEdges(std::vector<territory>({alaska, northwest_territory, ontario, western_united_states}));
    territories[3] = alberta;

    ontario.addEdges(std::vector<territory>({northwest_territory, alberta, western_united_states, eastern_united_states, quebec, greenland}));
    territories[4] = ontario;

    quebec.addEdges(std::vector<territory>({ontario, eastern_united_states, greenland}));
    territories[5] = quebec;

    western_united_states.addEdges(std::vector<territory>({alberta, ontario, eastern_united_states, central_america}));
    territories[6] = western_united_states;

    eastern_united_states.addEdges(std::vector<territory>({quebec, ontario, western_united_states, central_america}));
    territories[7] = eastern_united_states;

    central_america.addEdges(std::vector<territory>({western_united_states, eastern_united_states, venezuela}));
    territories[8] = central_america;

    
    
    // South America
    venezuela.addEdges(std::vector<territory>({central_america, peru, brazil}));
    territories[9] = venezuela;

    peru.addEdges(std::vector<territory>({venezuela, brazil, argintina}));
    territories[10] = peru;
    
    argintina.addEdges(std::vector<territory>({peru, brazil}));
    territories[11] = argintina;
    
    brazil.addEdges(std::vector<territory>({venezuela, peru, argintina, north_africa}));
    territories[12] = brazil;

    
    
    // Africa
    north_africa.addEdges(std::vector<territory>({brazil, western_europe, southern_europe, egypt, east_africa, congo}));
    territories[13] = north_africa;
    
    egypt.addEdges(std::vector<territory>({north_africa, southern_europe, middle_east, east_africa}));
    territories[14] = egypt;
    
    east_africa.addEdges(std::vector<territory>({madagascar, south_africa, congo, north_africa, egypt, middle_east}));
    territories[15] = east_africa;
    
    congo.addEdges(std::vector<territory>({north_africa, east_africa, south_africa}));
    territories[16] = congo;
    
    south_africa.addEdges(std::vector<territory>({congo, east_africa, madagascar}));
    territories[17] = south_africa;
    
    madagascar.addEdges(std::vector<territory>({south_africa, east_africa}));
    territories[18] = madagascar;

    
    
    // Austrialia
    indonesia.addEdges(std::vector<territory>({siam, new_guinea, western_australia}));
    territories[19] = indonesia;
    
    new_guinea.addEdges(std::vector<territory>({indonesia, western_australia, eastern_australia}));
    territories[20] = new_guinea;
    
    eastern_australia.addEdges(std::vector<territory>({new_guinea, western_australia}));
    territories[21] = eastern_australia;
    
    western_australia.addEdges(std::vector<territory>({indonesia, eastern_australia, new_guinea}));
    territories[22] = western_australia;

    
    
    // Europe
    iceland.addEdges(std::vector<territory>({greenland, scandinavia, great_britan}));
    territories[23] = iceland;
    
    scandinavia.addEdges(std::vector<territory>({iceland, great_britan, northern_europe, ukraine}));
    territories[24] = scandinavia;
    
    ukraine.addEdges(std::vector<territory>({scandinavia, northern_europe, southern_europe, middle_east, afghanistan, ural}));
    territories[25] = ukraine;
    
    great_britan.addEdges(std::vector<territory>({iceland, western_europe, northern_europe, scandinavia}));
    territories[26] = great_britan;
    
    northern_europe.addEdges(std::vector<territory>({scandinavia, great_britan, western_europe, southern_europe, ukraine}));
    territories[27] = northern_europe;
    
    western_europe.addEdges(std::vector<territory>({great_britan, northern_europe, southern_europe, north_africa}));
    territories[28] = western_europe;
    
    southern_europe.addEdges(std::vector<territory>({north_africa, egypt, middle_east, ukraine, northern_europe, western_europe}));
    territories[29] = southern_europe;

    
    
    // Aisa
    ural.addEdges(std::vector<territory>({ukraine, afghanistan, china, siberia}));
    territories[30] = ural;
    
    siberia.addEdges(std::vector<territory>({ural, china, mongolia, irkutsk, yakutsk}));
    territories[31] = siberia;
    
    yakutsk.addEdges(std::vector<territory>({siberia, irkutsk, kamchatka}));
    territories[32] = yakutsk;
    
    kamchatka.addEdges(std::vector<territory>({yakutsk, irkutsk, mongolia, japan, alaska}));
    territories[33] = kamchatka;
    
    irkutsk.addEdges(std::vector<territory>({siberia, yakutsk, kamchatka, mongolia}));
    territories[34] = irkutsk;
    
    mongolia.addEdges(std::vector<territory>({siberia, irkutsk, kamchatka, japan, china}));
    territories[35] = mongolia;
    
    japan.addEdges(std::vector<territory>({mongolia, kamchatka}));
    territories[36] = japan;
    
    afghanistan.addEdges(std::vector<territory>({ukraine, ural, china, india, middle_east}));
    territories[37] = afghanistan;
    
    china.addEdges(std::vector<territory>({siam, india, afghanistan, ural, siberia, mongolia}));
    territories[38] = china;
    
    middle_east.addEdges(std::vector<territory>({east_africa, egypt, southern_europe, ukraine, afghanistan, india}));
    territories[39] = middle_east;
    
    india.addEdges(std::vector<territory>({middle_east, afghanistan, china, siam}));
    territories[40] = india;
    
    siam.addEdges(std::vector<territory>({india, china, indonesia}));
    territories[41] = siam;

    std::cout << "Hello Ter" << territories[0].name << std::endl;
}