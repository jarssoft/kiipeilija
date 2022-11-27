#include <stdio.h>
#include <vector>

#ifndef VUORISTO_H_INCLUDED
#define VUORISTO_H_INCLUDED

/**
    Fraktaalivuoristo
*/
const double ALAPIIRTORAJA=-1;

struct korkeusJaKaltevuus {
    double korkeus;
    double kaltevuus;
};

//static double epatas[] = {1, 2, 5, 2, 4, 2, 50};

class Vuoristo {

    public:

        Vuoristo(double x1, double y1, double x2, double y2,
                double epatasaisuus):
                vasenP(NULL), oikeaP(NULL),
                x1(x1), y1(y1), x2(x2), y2(y2),
                epatasaisuus(epatasaisuus), syvyys(0)
                {}

        Vuoristo(double x1, double y1, double x2, double y2,
                double epatasaisuus, int syvyys):
                vasenP(NULL), oikeaP(NULL),
                x1(x1), y1(y1), x2(x2), y2(y2),
                epatasaisuus(epatasaisuus), syvyys(syvyys)
                {}

        /** Piirt�� vuoriston halutulla syvyydell�. */
        void piirra(int syvyys);

        /** Laskee maaston korkeuden halutulle koordinaatille. */
        struct korkeusJaKaltevuus getKorkeus(float x, int syvyys);

        void toString();

        void makeLU(const int resoluutio, const int syvyys);

        struct korkeusJaKaltevuus getKorkeusLU(float x);

    private:

        Vuoristo *vasenP;
        Vuoristo *oikeaP;

        /** Jakaa osan, ja palauttaa taulukkona vasemman ja oikean puolen. */
        struct vuoristoJako jaa();

        double x1, y1, x2, y2, epatasaisuus, katkaisukohta;

        int syvyys;

        std::vector<korkeusJaKaltevuus> lookup;

        double lookup_askel = 0;

        double index_askel = 0;

};


#endif // VUORISTO_H_INCLUDED
