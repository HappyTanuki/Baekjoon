#include <iostream>
#include <fstream>
#include <string>

int hanmaker() {
	std::string inputString;

	std::ifstream input("한별이.txt");
	std::ofstream output("한별이.cpp");

	do {
		std::getline(input, inputString);
		output << "std::cout << \"" << inputString << "\" << \'\\n\';" << '\n';
	} while (!input.eof());

	return 0;
}

int main() {
	std::cout << "                                                           :8DDDDDDDDDDDDDD$.                                           " << '\n';
	std::cout << "                                                      DDDNNN8~~~~~~~~~~=~7DNNDNDDDNNI                                   " << '\n';
	std::cout << "                                                  ?NNDD=~=~~~~~~~~~~~~~~~~~=~~==~=INNDNN7                               " << '\n';
	std::cout << "                                               +NDDI~~~~~~~~~~~~~~~~~~~~~~~=~~========~ODND+                            " << '\n';
	std::cout << "                                            :NND~~~~~~~~~~~~~~~~~~~~~~~~~~~=~~============7NDN                          " << '\n';
	std::cout << "                                          $DD$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=~~==============~DNN                        " << '\n';
	std::cout << "                                        $DD=~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=~~=================NND                      " << '\n';
	std::cout << "                                       ND7~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=~~===================DD7                    " << '\n';
	std::cout << "                                     ~DD=~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=======================8DN.                  " << '\n';
	std::cout << "                                    8DO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=========================DD                  " << '\n';
	std::cout << "                                   8N~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=~~=======================DN                 " << '\n';
	std::cout << "                                  NN::::::::~~~~~~~~~~~=~~~~~~~~~~~~~~~~~~~=~~========================DDO               " << '\n';
	std::cout << "                                 $D$:::::::::::::::~~~~DD~~~~~~~~~~~~~~~~~~=~~=========================DN.              " << '\n';
	std::cout << "                                 D8:::::::::::::::::::DN=::~~~~~~~~~~~~~~~~=~~======================~~:~DN              " << '\n';
	std::cout << "                                DN:::::::::::::::::::ONO::::::::::::::::::::~~~~~~~~~~~~:::::::::::::::::DN             " << '\n';
	std::cout << "                               DN::::::::::::::::::::NN.:::::::::::::::::::::::::::DN::::::::::::::::::::$DO            " << '\n';
	std::cout << "                               DD:::::::::::::::::::DNI:::::::::::::::::::::::::::::D=::::::::::::::::::::NN            " << '\n';
	std::cout << "                              NN~~~~:::::$N?:::::::.NN::::::::::::::::::::::::::::::ND.:::::::::::::::::::+N8           " << '\n';
	std::cout << "                              N7~~~~~~~~OD7::::::::~DD::::::::::::::::::::::::::::::~D$::::::::::::::::::::DN           " << '\n';
	std::cout << "                             NN~~~~~~~~IDZ~~~~~::::DN~:::::::::::::::::::::::::::::::DN::::::::::::::::::::=N~          " << '\n';
	std::cout << "                             DD~~~~~~~~NN~~~~~~~~~=NN::::::::::::::::::::::::::::::::DN:::::::::::::::~~====NN          " << '\n';
	std::cout << "                            8D~~~~~~~~ND~~~~~~~~~~~ND~~~~~~~~:::::::::::::::::::::::::N7:::~~===============NN          " << '\n';
	std::cout << "                            DD~~~~~~~ON+~~~~~~~~~~~ND~~~~~~~~~~~~~~~~~~~=+NZ==========NN====================~ND         " << '\n';
	std::cout << "               :DD7   DNDD. N8~~~~~~~NN~~~~~~~~~~DDND~~~~~~~~~~~~~~~~~~~~ND~~=========DD=====================ND         " << '\n';
	std::cout << "               N~:DDNNN .8NDN~~~~~~~$D=~~~~~~~~+ND.DD~~~~~~~~~~~~~~~~~~~=DD~~=========~D+====================DN         " << '\n';
	std::cout << "              :D     .  ..~ND~~~~~~~NN~~~~~~~+NN$..ND~~~~~~~~~~~~~~~~~~~7N=~~=========~ND=======~============ON         " << '\n';
	std::cout << "              NN       ...:N?~~~~~~~N=~~~~~NNNI.. .7D+~~~~~~~~~~~~~~~~~=8NN~~==========NN=======N============$N         " << '\n';
	std::cout << "         N  ODN       ....DN~~~~~~~DD=8NNND$..     .DD~~~=~~~~~~~~~~~~~=NNDD=~=========8D~======NN===========~N$        " << '\n';
	std::cout << "    N? =NN  ND      .....NND~~~~~~~DDNN:...        .ND=~DNN~~~~~~~~~~~~=DN.DN~=========?N+======NN============ND        " << '\n';
	std::cout << "   $D? DN    DZ    ....ND8NN~~~~~~$D                .DD~NNDD~~~~~~~~~~~~D8..DN=========~DN======NN============DN        " << '\n';
	std::cout << "   DN ~N~   NN    ..:~NN..NZ~~~~~~DN                  NNN8.ND~~~~NDN?~~~DZ...7DD=======~NN======NN============DN        " << '\n';
	std::cout << "   ND DD    :DN.  ..ND$  .N?~~~~~=NNN                   . ..DDD$~N8OND8=N+   ..DDDZ~====NN======+D+===========ND        " << '\n';
	std::cout << "   NO         DD  ZDN    8NO~~~~~~NNN..DDDNN7               ...NND...:DDD:     .:.NDND=~DD======~DO===========DN        " << '\n';
	std::cout << "              DNDDN:.    DN~~~~~~=NNNN.ODNNNNDDNNO              ...     .         ...DNNNN=======ND===========DD        " << '\n';
	std::cout << "       INDN7    DD.     .DD~~~~~=IDND:.:~.....?DNDNN.                        ...... ....$D=======ND===========ND        " << '\n';
	std::cout << "       NN        ND.    8N=~~~~$ND::.:=~:.~=......=ND~                 .NNNNNNNNNNNNNNN.~N+======NN===========DN        " << '\n';
	std::cout << "       $DD        DN:   DD~~~~7NO...~==.:~~:.....                      NNNND? ..::..7NZ.:N?======8D~==========ZN        " << '\n';
	std::cout << "       DN?     ~D: DND.?D~~~~~DD....~:.~=~.......                            ....~=:.:~..ND======~N$==========~DO       " << '\n';
	std::cout << "       ND    ..DD.  .DNDN=~~~~DI.......:.........                           ....=~..~~~..DN======~DD===========NN       " << '\n';
	std::cout << "       DDD  :.:DD.  . DDI~~~~~ND................        .DNNNNNNNNNN7      ....=~:.:~~...NN=======ND===========?D~      " << '\n';
	std::cout << "       8D. ...OD..    DD~~~~~~+ND ............          NN:~::::~~~8N      ........~~...:ND=======DN============NN      " << '\n';
	std::cout << "       DDI:...ND     .D7~~~~~~~7NN ..........           ID8::::::::8D      .............:DN=======ON============NN      " << '\n';
	std::cout << "        ~NNND.N=.   .NN~~~~~~~~~NDN8                       ~::::::~N8       .............DN========D=============NI     " << '\n';
	std::cout << "               DDNNN.ND~~~~~~~~DD =DND                                       ............DN========N+~===========NN     " << '\n';
	std::cout << "                   ~:N=~~~~~~~~DD   .DDDD                                       ........ NN========DD============8D     " << '\n';
	std::cout << "                    8N~~~~~~~~~ND    . .7NDDD? .                                      .8DDN========NN=============D:    " << '\n';
	std::cout << "                    DD~~~~~~~~~DND:         IDNNND$.                           .+DNNNNDNIDN========DD=============DD    " << '\n';
	std::cout << "                    ND~~~~~~~~ZN 7DD .. .:DDNDDNNDNNNNDDNDND8$?===+$8DDNNNDDDDDN8I~DN====8N========NN=============NN    " << '\n';
	std::cout << "                    DD~~~~~~~~8N   DD.  .NN~~~~.~~=DNDNO.:7ODDDDNNDD8DDDND=~~~ =~~~ON====8N========DN=============DN    " << '\n';
	std::cout << "                    ND~~~~~~~~DN    ZDD  DN~~~ ~~~~~=.7DDD+.......8NNN==~~~~~ ~~~~~ONN$==DN========8N=============ON    " << '\n';
	std::cout << "                    ND~8N~=~~~ZN      DDODN=~.~~~~~=.~~~~INDNNNNDNN~~~~~~~~:~~~~~~~DN~ND=DN========DD=========~ND=8N    " << '\n';
	std::cout << "                    IN=NDDI~~~~D8       DNN::~~~~~.~~~~~=.~~ND~~ND~~~~~~~~.~~~~~~~~NN  NDNN====ND==ND~D?======DNN=ND    " << '\n';
	std::cout << "                     DNNI8ND=~~DN:       ZN=~~~~~ ~~~~~.~~~~DD~=DD~~~~~~~ ~~~~~~~=.ND. . ND===DNDD=NDDNN=====8NZDDDN    " << '\n';
	std::cout << "                      NND  IDNDNNN+       D+~~~:~~~~~~ ~~~~~DDNNN+~~~~~~~~~~~~~~:=?N7   .ND=~ND  DNNN~ID====ND7 NNN     " << '\n';
	std::cout << "                       ID                 ND~~ ~~~~~:.~~~7DDN7IDNN==~~ ~~~~~~~~ ~~DN   .:N?DDDDD NND  8N~=DDD  ZNN      " << '\n';
	std::cout << "                                          NN~:~~~~~ =7DDDD+8N  :N8DDZ.~~~~~~~~.~~~DD.   NDD+ . DN=     OND+             " << '\n';
	std::cout << "                                          DND~~~=8DNDDZ=~~ ND   NN~INND~~~~~.~~~~ND .    .    ..IDD                     " << '\n';
	std::cout << "                                         DDNNNDNNN+~~~~~~.7N.    ND~~~NDDI~ ~~~~=NNN             .DDI                   " << '\n';
	std::cout << "                                        DN=~~~~.=~~~~~~ ~~DN     +N+~~~~+DNDD~~~NNNND.            ..ND                  " << '\n';
	std::cout << "                                         DDI~~ ~~~~~~~ ~~~ND..  ..ND~~~~:~~~DNDNNNN+            ..7O8ND+                " << '\n';
	std::cout << "                                          .DND=~~~~=::~~=NN.   . . 8D~~.~~~~~~=DN$ODNDNDNNNDNNNNND8+~..                 " << '\n';
	std::cout << "                                             8DNNI=.~~~~=NDDNNNNDDNDNN.~~~~~IDDNDND7:.                                  " << '\n';
	std::cout << "                                                ?DNNDD?~DD          ~NN~~=NDD$                                          " << '\n';
	std::cout << "                                                     :DDD.            NNNN=                                             " << '\n';
}