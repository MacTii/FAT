/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Kamil Szustak
 * Test wygenerowano automatycznie o 2022-12-14 12:49:03.395447
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("SAND.TX");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("forest.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1412, 1);
                char expected_filecontent[1413] = "";
        
                strcat(expected_filecontent, "wrought in Scaevola\nTo his own hand remorseless, to the path,\nWhence they were drawn, their steps had hasten\'d back,\nWhen liberty return\'d: but in too few\nResolve so steadfast dwells.  And by these words\nIf duly weigh\'d, that argument is void,\nWhich oft might have perplex\'d thee still.  But now\nAnother question thwarts thee, which to solve\nMight try thy patience without better aid.\nI have, no doubt, instill\'d into thy mind,\nThat blessed spirit may not lie; since near\nThe source of primal truth it dwells for aye:\nAnd thou might\'st after of Piccarda learn\nThat Constance held affection to the veil;\nSo that she seems to contradict me here.\nNot seldom, brother, it hath chanc\'d for men\nTo do what they had gladly left undone,\nYet to shun peril they have done amiss:\nE\'en as Alcmaeon, at his father\'s suit\nSlew his own mother, so made pitiless\nNot to lose pity.  On this point bethink thee,\nThat force and will are blended in such wise\nAs not to make the\' offence excusable.\nAbsolute will agrees not to the wrong,\nThat inasmuch as there is fear of woe\nFrom non-compliance, it agrees.  Of will\nThus absolute Piccarda spake, and I\nOf th\' other; so that both have truly said.\"\n     Such was the flow of that pure rill, that well\'d\nFrom forth the fountain of all truth; and such\nThe rest, that to my wond\'ring thoughts l found.\n      \"O thou of primal love the prime delight!\nGoddess!  \"I straight reply\'d, \"whose ");
                
        
                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "AMONG.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1412, file);
                test_error(size == 1412, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1412 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1412);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1412);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(8424, 1);
                char expected_filecontent[8425] = "";
        
                strcat(expected_filecontent, " the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total reverse of fortune should\nensue, as a punishment for his acts of treachery and guilt:  for\nhe was said to have poisoned the Count Anselmo da Capraia, his\nsister\'s son, on account of the envy and fear excited in his mind\nby the high esteem in which the gracious manners of Anselmo were\nheld by the Pisans.  The power of the Guelphi being so much\ndiminished, the Archbishop devised means to betray the Count\nUglino and caused him to be suddenly attacked in his palace by\nthe fury of the people, whom he had exasperated, by telling them\n");
    strcat(expected_filecontent, "that Ugolino had betrayed Pisa, and given up their castles to the\ncitizens of Florence and of Lucca. He was immediately compelled\nto surrender; his bastard son and his grandson fell in the\nassault; and two of his sons, with their two sons also, were\nconveyed to prison.\"  G. Villani l. vii. c. 120.\n\n\"In the following march, the Pisans, who had imprisoned the Count\nUglino, with two of his sons and two of his grandchildren, the\noffspring of his son the Count Guelfo, in a tower on the Piazza\nof the Anzania, caused the tower to be locked, the key thrown\ninto the Arno, and all food to be withheld from them.  In a few\ndays they died of hunger; but the Count first with loud cries\ndeclared his penitence, and yet neither priest nor friar was\nallowed to shrive him.  All the five, when dead, were dragged out\nof the prison, and meanly interred; and from thence forward the\ntower was called the tower of famine, and so shall ever be.\"\nIbid. c. 127.\n\nChancer has briefly told Ugolino\'s story. See Monke\'s Tale,\nHugeline of Pise.\n\nv. 29.  Unto the mountain.]  The mountain S. Giuliano, between\nPisa and Lucca.\n\nv. 59. Thou gav\'st.]\n               Tu ne vestisti\n        Queste misere carni, e tu le spoglia.\nImitated by Filicaja, Canz. iii.\n        Di questa imperial caduca spoglia\n        Tu, Signor, me vestisti e tu mi spoglia:\n        Ben puoi\'l Regno me tor tu che me\'l desti.\nAnd by Maffei, in the Merope:\n               Tu disciogleste\n        Queste misere membra e tu le annodi.\n\nv. 79. In that fair region.]\n        Del bel paese la, dove\'l si suona.\nItaly as explained by Dante himself, in his treatise De Vulg.\nEloq. l. i. c. 8. \"Qui autem Si dicunt a praedictis finibus.\n(Januensiem) Oreintalem (Meridionalis Europae partem) tenent;\nvidelicet usque ad promontorium illud Italiae, qua sinus\nAdriatici maris incipit et Siciliam.\"\n\nv. 82.  Capraia and Gorgona.]  Small islands near the mouth of\nthe Arno.\n\nv. 94.  There very weeping suffers not to weep,]\n        Lo pianto stesso li pianger non lascia.\nSo Giusto de\'Conti, Bella Mano. Son. \"Quanto il ciel.\"\n        Che il troppo pianto a me pianger non lassa.\nv. 116.  The friar Albigero.]  Alberigo de\'Manfredi, of Faenza,\none of the Frati Godenti, Joyons Friars who having quarrelled\nwith some of his brotherhood, under pretence of wishing to be\nreconciled, invited them to a banquet, at the conclusion of which\nhe called for the fruit, a signal for the assassins to rush in\nand dispatch those whom he had marked for destruction.  Hence,\nadds Landino, it is said proverbially of one who has been\nstabbed, that he has had some of the friar Alberigo\'s fruit.\nThus Pulci, Morg. Magg. c. xxv.\n        Le frutte amare di frate Alberico.\n\nv. 123.  Ptolomea.]  This circle is named Ptolomea from Ptolemy,\nthe son of Abubus, by whom Simon and his sons were murdered, at a\ngreat banquet he had made for them. See Maccabees, ch xvi.\n\nv. 126.  The glazed tear-drops.]\n\n        -sorrow\'s eye, glazed with blinding tears.\n               Shakspeare, Rich. II. a. 2. s. 2.\n\nv. 136.  Branca Doria.]  The family of Doria was possessed of\ngreat influence in Genoa.  Branca is said to have murdered his\nfather-in-law, Michel Zanche, introduced in Canto XXII.\n\nv. 162  Romagna\'s darkest spirit.]  The friar Alberigo.\n\n\n\nCanto XXXIV.\n\nv. 6.  A wind-mill.]  The author of the Caliph Vathek, in the\nnotes to that tale, justly observes, that it is more than\nprobable that Don Quixote\'s mistake of the wind-mills for giants\nwas suggested to Cervantes by this simile.\n\nv. 37. Three faces.]  It can scarcely be doubted but that Milton\nderived his description of Satan in those lines,\n\n               Each passion dimm\'d his face\n        Thrice chang\'d with pale, ire, envy, and despair.\n               P. L. b. iv. 114.\nfrom this passage, coupled with the remark of Vellutello upon it:\n\n\"The first of these sins is anger which he signifies by the red\nface; the second, represented by that between pale and yellow is\nenvy and not, as others have said, avarice; and the third,\ndenoted by the black, is a melancholy humour that causes a man\'s\nthoughts to be dark an");
    strcat(expected_filecontent, "d evil, and averse from all joy and\ntranquillity.\"\n\nv. 44. Sails.]\n               --His sail-broad vans\n        He spreads for flight.\n               Milton, P. L. b. ii. 927.\nCompare Spenser, F. Q. b. i. c. xi. st. 10;  Ben Jonson\'s ");
                
        
                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "PROCESS.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 8424, file);
                test_error(size == 8424, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 8424 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 8424);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 8424);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6595, 1);
                char expected_filecontent[6596] = "";
        
                strcat(expected_filecontent, "ven now such aid, that to retrace your forms\nIs easier.  Yet inform me, ye, who here\nAre happy, long ye for a higher place\nMore to behold, and more in love to dwell?\"\n     She with those other spirits gently smil\'d,\nThen answer\'d with such gladness, that she seem\'d\nWith love\'s first flame to glow:  \"Brother!  our will\nIs in composure settled by the power\nOf charity, who makes us will alone\nWhat we possess, and nought beyond desire;\nIf we should wish to be exalted more,\nThen must our wishes jar with the high will\nOf him, who sets us here, which in these orbs\nThou wilt confess not possible, if here\nTo be in charity must needs befall,\nAnd if her nature well thou contemplate.\nRather it is inherent in this state\nOf blessedness, to keep ourselves within\nThe divine will, by which our wills with his\nAre one.  So that as we from step to step\nAre plac\'d throughout this kingdom, pleases all,\nE\'en as our King, who in us plants his will;\nAnd in his will is our tranquillity;\nIt is the mighty ocean, whither tends\nWhatever it creates and nature makes.\"\n     Then saw I clearly how each spot in heav\'n\nIs Paradise, though with like gracious dew\nThe supreme virtue show\'r not over all.\n     But as it chances, if one sort of food\nHath satiated, and of another still\nThe appetite remains, that this is ask\'d,\nAnd thanks for that return\'d; e\'en so did I\nIn word and motion, bent from her to learn\nWhat web it was, through which she had not drawn\nThe shuttle to its point.  She thus began:\n\"Exalted worth and perfectness of life\nThe Lady higher up enshrine in heaven,\nBy whose pure laws upon your nether earth\nThe robe and veil they wear, to that intent,\nThat e\'en till death they may keep watch or sleep\nWith their great bridegroom, who accepts each vow,\nWhich to his gracious pleasure love conforms.\nfrom the world, to follow her, when young\nEscap\'d; and, in her vesture mantling me,\nMade promise of the way her sect enjoins.\nThereafter men, for ill than good more apt,\nForth snatch\'d me from the pleasant cloister\'s pale.\nGod knows how after that my life was fram\'d.\nThis other splendid shape, which thou beholdst\nAt my right side, burning with all the light\nOf this our orb, what of myself I tell\nMay to herself apply.  From her, like me\nA sister, with like violence were torn\nThe saintly folds, that shaded her fair brows.\nE\'en when she to the world again was brought\nIn spite of her own will and better wont,\nYet not for that the bosom\'s inward veil\nDid she renounce.  This is the luminary\nOf mighty Constance, who from that loud blast,\nWhich blew the second over Suabia\'s realm,\nThat power produc\'d, which was the third and last.\"\n     She ceas\'d from further talk, and then began\n\"Ave Maria\" singing, and with that song\nVanish\'d, as heavy substance through deep wave.\n     Mine eye, that far as it was capable,\nPursued her, when in dimness she was lost,\nTurn\'d to the mark where greater want impell\'d,\nAnd bent on Beatrice all its gaze.\nBut she as light\'ning beam\'d upon my looks:\nSo that the sight sustain\'d it not at first.\nWhence I to question her became less prompt.\n\n\n\nCANTO IV\n\nBetween two kinds of food, both equally\nRemote and tempting, first a man might die\nOf hunger, ere he one could freely choose.\nE\'en so would stand a lamb between the maw\nOf two fierce wolves, in dread of both alike:\nE\'en so between two deer a dog would stand,\nWherefore, if I was silent, fault nor praise\nI to myself impute, by equal doubts\nHeld in suspense, since of necessity\nIt happen\'d.  Silent was I, yet desire\nWas painted in my looks; and thus I spake\nMy wish more earnestly than language could.\n     As Daniel, when the haughty king he freed\nFrom ire, that spurr\'d him on to deeds unjust\nAnd violent; so look\'d Beatrice then.\n     \"Well I discern,\" she thus her words address\'d,\n\"How contrary desires each way constrain thee,\nSo that thy anxious thought is in itself\nBound up and stifled, nor breathes freely forth.\nThou arguest; if the good intent remain;\nWhat reason that another\'s violence\nShould stint the measure of my fair desert?\n     \"Cause too thou findst for doubt, in that it seems,\nThat sp");
    strcat(expected_filecontent, "irits to the stars, as Plato deem\'d,\nReturn.  These are the questions which thy will\nUrge equally; and therefore I the first\nOf that will treat which hath the more of gall.\nOf seraphim he who is most ensky\'d,\nMoses and Samuel, and either John,\nChoose which thou wilt, nor even Mary\'s self,\nHave not in any other heav\'n their seats,\nThan have those spirits which so late thou saw\'st;\nNor more or fewer years exist; but all\nMake the first circle beauteous, diversely\nPartaking of sweet life, as more or less\nAfflation of eternal bliss pervades them.\nHere were they shown thee, not that fate assigns\nThis for their sphere, but for a sign to thee\nOf that celestial furthest from the height.\nThus needs, that ye may apprehend, we speak:\nSince from things sensible alone ye learn\nThat, which digested rightly after turns\nTo intellectual.  For no other cause\nThe scripture, condescending graciously\nTo your perception, hands and feet to God\nAttributes, nor so means: and holy church\nDoth represent with human countenance\nGabriel, and Michael, and him who made\nTobias whole.  Unlike what here thou seest,\nThe judgment of Timaeus, who affirms\nEach soul restor\'d to its particular star,\nBelieving it to have been taken thence,\nWhen nature gave it to inform her mold:\nSince to appearance his intention is\nE\'en what his words declare: or else to shun\nDerision, haply thus he hath disguis\'d\nHis true opinion.  If his meaning be,\nThat to the influencing of these orbs revert\nThe honour and the blame in human acts,\nPerchance he doth not wholly miss the truth.\nThis principle, not understood aright,\nErewhile perverted well nigh all the world;\nSo that it fell to fabled names of Jove,\nAnd Mercury, and Mars.  That other doubt,\nWhich moves thee, is less harmful; for it brings\nNo peril of removing thee from me.\n     \"That, to the eye of man, our justice seems\nUnjust, is argument for faith, and not\nFor heretic declension.  To the end\nThis truth may stand more clearly in your view,\nI will content thee even to thy wish\n     \"If violence be, when that which suffers, nought\nConsents to that which forceth, not for this\nThese spirits stood exculpate.  For the will,\nThat will not, still survives unquench\'d, and doth\nAs nature doth in fire, tho\' violence\nWrest it a thousand times; for, if it yield\nOr more or less, so far it follows force.\nAnd thus did these, whom they had power to seek\nThe hallow\'d place again.  In them, had will\nBeen perfect, such as once upon the bars\nHeld Laurence firm, or wrought in Scaevol");
                
        
                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SEND");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6595, file);
                test_error(size == 6595, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6595 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6595);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6595);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6530, 1);
                char expected_filecontent[6531] = "";
        
                strcat(expected_filecontent, " pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nTh");
    strcat(expected_filecontent, "e grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWer");
                
        
                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "ROW");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6530, file);
                test_error(size == 6530, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6530 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6530);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6530);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(12288, 1);
                char expected_filecontent[12289] = "";
        
                strcat(expected_filecontent, "lated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure");
    strcat(expected_filecontent, " (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John XXII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exclamation on the degeneracy of human nature,\nwhich does not lift itself to the contemplation of divine things.\n\nv. 126.  The fair child of him.]  So she calls human nature.\nPindar by a more easy figure, terms the day, \"child of the sun.\"\n\nv. 129.  None.]  Because, as has been before said, the shepherds\nare become wolves.\n\nv. 131.  Before the date.]  \"Before many ages are past, before\nthose fractions, which are drops in the reckoning of every year,\nshall amount to so large a portion of time, that January shall be\nno more a winter month.\" By this periphrasis is meant \" in a\nshort time,\" as we say familiarly, such a thing will happen\nbefore a thousand years are over when we mean, it will happen\nsoon.\n\nv. 135.  Fortune shall be fain.]  The commentators in general\nsuppose that our Poet here augurs that great reform, which he\nvainly hoped would follow on the arrival of the Emperor Henry\nVII. in Italy. Lombardi refers the prognostication to Can Grande\ndella Scala: and, when we consider that this Canto was not\nfinished till after the death of  Henry, as appears from the\nmention that is made of John XXII, it cannot be denied but the\nconjecture is probable.\n\nCANTO XXVIII\n\nv. 36.  Heav\'n, and all nature, hangs upon that point.]  [GREEK\nHERE]\nAristot. Metaph. 1. xii. c. 7.  \"From that beginning depend\nheaven and nature.\"\n\nv. 43.  Such diff\'rence.]  The material world and the\nintelligential (the copy and the pattern) appear to Dante to\ndiffer in this respect, that the orbits of the latter are more\nswift, the nearer they are to the centre, whereas the contrary is\nthe case with the orbits of the former. The seeming contradiction\nis thus accounted for by Beatrice.  In the material world, the\nmore ample the body is, the greater is the good of which itis\ncapable supposing all the parts to be equally perfect. But in the\nintelligential world, the circles are more excellent and\npowerful, the more they approximate to the central point, which\nis God.  Thus the first circle, that of the seraphim, corresponds\nto the ninth sphere, or primum mobile, the second, that of the\ncherubim, to the eighth sphere, or heaven of fixed stars; the\nthird, or circle of thrones, to the seventh sphere, or planet of\nSaturn; and in like manner throughout the two other trines of\ncircles and spheres.\n\nIn orbs\nOf circuit inexpressible they stood,\nOrb within orb\nMilton, P. L. b. v. 596.\n\nv. 70.  The sturdy north.]  Compare Homer, II. b. v. 524.\n\nv. 82.  In number.]  The sparkles exceeded the number which would\nbe produced by the sixty-four squares of a chess-board, if for\nthe first we reckoned one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nigh");
    strcat(expected_filecontent, "tly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part of the\ncreation, which participates both of spirit and matter, were\nproduced at once.\n\nv. 38.  On Jerome\'s pages.]  St. Jerome had described the angels\nas created before the rest of the universe: an opinion which\nThomas  Aquinas controverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye c");
    strcat(expected_filecontent, "omm");
                
        
                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "CATCH.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 12288, file);
                test_error(size == 12288, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12288 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12288);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 12288);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(12356, 1);
                char expected_filecontent[12357] = "";
        
                strcat(expected_filecontent, " him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefo");
    strcat(expected_filecontent, "re on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards u");
    strcat(expected_filecontent, "s came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer know");
    strcat(expected_filecontent, "n,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit dow");
                
        
                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "BEHIND.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 12356, file);
                test_error(size == 12356, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12356 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12356);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 12356);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1230, 1);
                char expected_filecontent[1231] = "";
        
                strcat(expected_filecontent, "  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thu");
                
        
                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "BROKELAN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1230, file);
                test_error(size == 1230, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1230 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1230);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1230);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1412, 1);
                char expected_filecontent[1413] = "";

                strcat(expected_filecontent, "wrought in Scaevola\nTo his own hand remorseless, to the path,\nWhence they were drawn, their steps had hasten\'d back,\nWhen liberty return\'d: but in too few\nResolve so steadfast dwells.  And by these words\nIf duly weigh\'d, that argument is void,\nWhich oft might have perplex\'d thee still.  But now\nAnother question thwarts thee, which to solve\nMight try thy patience without better aid.\nI have, no doubt, instill\'d into thy mind,\nThat blessed spirit may not lie; since near\nThe source of primal truth it dwells for aye:\nAnd thou might\'st after of Piccarda learn\nThat Constance held affection to the veil;\nSo that she seems to contradict me here.\nNot seldom, brother, it hath chanc\'d for men\nTo do what they had gladly left undone,\nYet to shun peril they have done amiss:\nE\'en as Alcmaeon, at his father\'s suit\nSlew his own mother, so made pitiless\nNot to lose pity.  On this point bethink thee,\nThat force and will are blended in such wise\nAs not to make the\' offence excusable.\nAbsolute will agrees not to the wrong,\nThat inasmuch as there is fear of woe\nFrom non-compliance, it agrees.  Of will\nThus absolute Piccarda spake, and I\nOf th\' other; so that both have truly said.\"\n     Such was the flow of that pure rill, that well\'d\nFrom forth the fountain of all truth; and such\nThe rest, that to my wond\'ring thoughts l found.\n      \"O thou of primal love the prime delight!\nGoddess!  \"I straight reply\'d, \"whose ");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "AMONG.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1582, file);
                test_error(size == 1412, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1412 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1412);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1412);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(8424, 1);
                char expected_filecontent[8425] = "";

                strcat(expected_filecontent, " the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total reverse of fortune should\nensue, as a punishment for his acts of treachery and guilt:  for\nhe was said to have poisoned the Count Anselmo da Capraia, his\nsister\'s son, on account of the envy and fear excited in his mind\nby the high esteem in which the gracious manners of Anselmo were\nheld by the Pisans.  The power of the Guelphi being so much\ndiminished, the Archbishop devised means to betray the Count\nUglino and caused him to be suddenly attacked in his palace by\nthe fury of the people, whom he had exasperated, by telling them\n");
    strcat(expected_filecontent, "that Ugolino had betrayed Pisa, and given up their castles to the\ncitizens of Florence and of Lucca. He was immediately compelled\nto surrender; his bastard son and his grandson fell in the\nassault; and two of his sons, with their two sons also, were\nconveyed to prison.\"  G. Villani l. vii. c. 120.\n\n\"In the following march, the Pisans, who had imprisoned the Count\nUglino, with two of his sons and two of his grandchildren, the\noffspring of his son the Count Guelfo, in a tower on the Piazza\nof the Anzania, caused the tower to be locked, the key thrown\ninto the Arno, and all food to be withheld from them.  In a few\ndays they died of hunger; but the Count first with loud cries\ndeclared his penitence, and yet neither priest nor friar was\nallowed to shrive him.  All the five, when dead, were dragged out\nof the prison, and meanly interred; and from thence forward the\ntower was called the tower of famine, and so shall ever be.\"\nIbid. c. 127.\n\nChancer has briefly told Ugolino\'s story. See Monke\'s Tale,\nHugeline of Pise.\n\nv. 29.  Unto the mountain.]  The mountain S. Giuliano, between\nPisa and Lucca.\n\nv. 59. Thou gav\'st.]\n               Tu ne vestisti\n        Queste misere carni, e tu le spoglia.\nImitated by Filicaja, Canz. iii.\n        Di questa imperial caduca spoglia\n        Tu, Signor, me vestisti e tu mi spoglia:\n        Ben puoi\'l Regno me tor tu che me\'l desti.\nAnd by Maffei, in the Merope:\n               Tu disciogleste\n        Queste misere membra e tu le annodi.\n\nv. 79. In that fair region.]\n        Del bel paese la, dove\'l si suona.\nItaly as explained by Dante himself, in his treatise De Vulg.\nEloq. l. i. c. 8. \"Qui autem Si dicunt a praedictis finibus.\n(Januensiem) Oreintalem (Meridionalis Europae partem) tenent;\nvidelicet usque ad promontorium illud Italiae, qua sinus\nAdriatici maris incipit et Siciliam.\"\n\nv. 82.  Capraia and Gorgona.]  Small islands near the mouth of\nthe Arno.\n\nv. 94.  There very weeping suffers not to weep,]\n        Lo pianto stesso li pianger non lascia.\nSo Giusto de\'Conti, Bella Mano. Son. \"Quanto il ciel.\"\n        Che il troppo pianto a me pianger non lassa.\nv. 116.  The friar Albigero.]  Alberigo de\'Manfredi, of Faenza,\none of the Frati Godenti, Joyons Friars who having quarrelled\nwith some of his brotherhood, under pretence of wishing to be\nreconciled, invited them to a banquet, at the conclusion of which\nhe called for the fruit, a signal for the assassins to rush in\nand dispatch those whom he had marked for destruction.  Hence,\nadds Landino, it is said proverbially of one who has been\nstabbed, that he has had some of the friar Alberigo\'s fruit.\nThus Pulci, Morg. Magg. c. xxv.\n        Le frutte amare di frate Alberico.\n\nv. 123.  Ptolomea.]  This circle is named Ptolomea from Ptolemy,\nthe son of Abubus, by whom Simon and his sons were murdered, at a\ngreat banquet he had made for them. See Maccabees, ch xvi.\n\nv. 126.  The glazed tear-drops.]\n\n        -sorrow\'s eye, glazed with blinding tears.\n               Shakspeare, Rich. II. a. 2. s. 2.\n\nv. 136.  Branca Doria.]  The family of Doria was possessed of\ngreat influence in Genoa.  Branca is said to have murdered his\nfather-in-law, Michel Zanche, introduced in Canto XXII.\n\nv. 162  Romagna\'s darkest spirit.]  The friar Alberigo.\n\n\n\nCanto XXXIV.\n\nv. 6.  A wind-mill.]  The author of the Caliph Vathek, in the\nnotes to that tale, justly observes, that it is more than\nprobable that Don Quixote\'s mistake of the wind-mills for giants\nwas suggested to Cervantes by this simile.\n\nv. 37. Three faces.]  It can scarcely be doubted but that Milton\nderived his description of Satan in those lines,\n\n               Each passion dimm\'d his face\n        Thrice chang\'d with pale, ire, envy, and despair.\n               P. L. b. iv. 114.\nfrom this passage, coupled with the remark of Vellutello upon it:\n\n\"The first of these sins is anger which he signifies by the red\nface; the second, represented by that between pale and yellow is\nenvy and not, as others have said, avarice; and the third,\ndenoted by the black, is a melancholy humour that causes a man\'s\nthoughts to be dark an");
    strcat(expected_filecontent, "d evil, and averse from all joy and\ntranquillity.\"\n\nv. 44. Sails.]\n               --His sail-broad vans\n        He spreads for flight.\n               Milton, P. L. b. ii. 927.\nCompare Spenser, F. Q. b. i. c. xi. st. 10;  Ben Jonson\'s ");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PROCESS.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 8899, file);
                test_error(size == 8424, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 8424 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 8424);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 8424);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6595, 1);
                char expected_filecontent[6596] = "";

                strcat(expected_filecontent, "ven now such aid, that to retrace your forms\nIs easier.  Yet inform me, ye, who here\nAre happy, long ye for a higher place\nMore to behold, and more in love to dwell?\"\n     She with those other spirits gently smil\'d,\nThen answer\'d with such gladness, that she seem\'d\nWith love\'s first flame to glow:  \"Brother!  our will\nIs in composure settled by the power\nOf charity, who makes us will alone\nWhat we possess, and nought beyond desire;\nIf we should wish to be exalted more,\nThen must our wishes jar with the high will\nOf him, who sets us here, which in these orbs\nThou wilt confess not possible, if here\nTo be in charity must needs befall,\nAnd if her nature well thou contemplate.\nRather it is inherent in this state\nOf blessedness, to keep ourselves within\nThe divine will, by which our wills with his\nAre one.  So that as we from step to step\nAre plac\'d throughout this kingdom, pleases all,\nE\'en as our King, who in us plants his will;\nAnd in his will is our tranquillity;\nIt is the mighty ocean, whither tends\nWhatever it creates and nature makes.\"\n     Then saw I clearly how each spot in heav\'n\nIs Paradise, though with like gracious dew\nThe supreme virtue show\'r not over all.\n     But as it chances, if one sort of food\nHath satiated, and of another still\nThe appetite remains, that this is ask\'d,\nAnd thanks for that return\'d; e\'en so did I\nIn word and motion, bent from her to learn\nWhat web it was, through which she had not drawn\nThe shuttle to its point.  She thus began:\n\"Exalted worth and perfectness of life\nThe Lady higher up enshrine in heaven,\nBy whose pure laws upon your nether earth\nThe robe and veil they wear, to that intent,\nThat e\'en till death they may keep watch or sleep\nWith their great bridegroom, who accepts each vow,\nWhich to his gracious pleasure love conforms.\nfrom the world, to follow her, when young\nEscap\'d; and, in her vesture mantling me,\nMade promise of the way her sect enjoins.\nThereafter men, for ill than good more apt,\nForth snatch\'d me from the pleasant cloister\'s pale.\nGod knows how after that my life was fram\'d.\nThis other splendid shape, which thou beholdst\nAt my right side, burning with all the light\nOf this our orb, what of myself I tell\nMay to herself apply.  From her, like me\nA sister, with like violence were torn\nThe saintly folds, that shaded her fair brows.\nE\'en when she to the world again was brought\nIn spite of her own will and better wont,\nYet not for that the bosom\'s inward veil\nDid she renounce.  This is the luminary\nOf mighty Constance, who from that loud blast,\nWhich blew the second over Suabia\'s realm,\nThat power produc\'d, which was the third and last.\"\n     She ceas\'d from further talk, and then began\n\"Ave Maria\" singing, and with that song\nVanish\'d, as heavy substance through deep wave.\n     Mine eye, that far as it was capable,\nPursued her, when in dimness she was lost,\nTurn\'d to the mark where greater want impell\'d,\nAnd bent on Beatrice all its gaze.\nBut she as light\'ning beam\'d upon my looks:\nSo that the sight sustain\'d it not at first.\nWhence I to question her became less prompt.\n\n\n\nCANTO IV\n\nBetween two kinds of food, both equally\nRemote and tempting, first a man might die\nOf hunger, ere he one could freely choose.\nE\'en so would stand a lamb between the maw\nOf two fierce wolves, in dread of both alike:\nE\'en so between two deer a dog would stand,\nWherefore, if I was silent, fault nor praise\nI to myself impute, by equal doubts\nHeld in suspense, since of necessity\nIt happen\'d.  Silent was I, yet desire\nWas painted in my looks; and thus I spake\nMy wish more earnestly than language could.\n     As Daniel, when the haughty king he freed\nFrom ire, that spurr\'d him on to deeds unjust\nAnd violent; so look\'d Beatrice then.\n     \"Well I discern,\" she thus her words address\'d,\n\"How contrary desires each way constrain thee,\nSo that thy anxious thought is in itself\nBound up and stifled, nor breathes freely forth.\nThou arguest; if the good intent remain;\nWhat reason that another\'s violence\nShould stint the measure of my fair desert?\n     \"Cause too thou findst for doubt, in that it seems,\nThat sp");
    strcat(expected_filecontent, "irits to the stars, as Plato deem\'d,\nReturn.  These are the questions which thy will\nUrge equally; and therefore I the first\nOf that will treat which hath the more of gall.\nOf seraphim he who is most ensky\'d,\nMoses and Samuel, and either John,\nChoose which thou wilt, nor even Mary\'s self,\nHave not in any other heav\'n their seats,\nThan have those spirits which so late thou saw\'st;\nNor more or fewer years exist; but all\nMake the first circle beauteous, diversely\nPartaking of sweet life, as more or less\nAfflation of eternal bliss pervades them.\nHere were they shown thee, not that fate assigns\nThis for their sphere, but for a sign to thee\nOf that celestial furthest from the height.\nThus needs, that ye may apprehend, we speak:\nSince from things sensible alone ye learn\nThat, which digested rightly after turns\nTo intellectual.  For no other cause\nThe scripture, condescending graciously\nTo your perception, hands and feet to God\nAttributes, nor so means: and holy church\nDoth represent with human countenance\nGabriel, and Michael, and him who made\nTobias whole.  Unlike what here thou seest,\nThe judgment of Timaeus, who affirms\nEach soul restor\'d to its particular star,\nBelieving it to have been taken thence,\nWhen nature gave it to inform her mold:\nSince to appearance his intention is\nE\'en what his words declare: or else to shun\nDerision, haply thus he hath disguis\'d\nHis true opinion.  If his meaning be,\nThat to the influencing of these orbs revert\nThe honour and the blame in human acts,\nPerchance he doth not wholly miss the truth.\nThis principle, not understood aright,\nErewhile perverted well nigh all the world;\nSo that it fell to fabled names of Jove,\nAnd Mercury, and Mars.  That other doubt,\nWhich moves thee, is less harmful; for it brings\nNo peril of removing thee from me.\n     \"That, to the eye of man, our justice seems\nUnjust, is argument for faith, and not\nFor heretic declension.  To the end\nThis truth may stand more clearly in your view,\nI will content thee even to thy wish\n     \"If violence be, when that which suffers, nought\nConsents to that which forceth, not for this\nThese spirits stood exculpate.  For the will,\nThat will not, still survives unquench\'d, and doth\nAs nature doth in fire, tho\' violence\nWrest it a thousand times; for, if it yield\nOr more or less, so far it follows force.\nAnd thus did these, whom they had power to seek\nThe hallow\'d place again.  In them, had will\nBeen perfect, such as once upon the bars\nHeld Laurence firm, or wrought in Scaevol");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SEND");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6709, file);
                test_error(size == 6595, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6595 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6595);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6595);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6530, 1);
                char expected_filecontent[6531] = "";

                strcat(expected_filecontent, " pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nTh");
    strcat(expected_filecontent, "e grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWer");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ROW");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6759, file);
                test_error(size == 6530, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6530 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6530);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6530);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(12288, 1);
                char expected_filecontent[12289] = "";

                strcat(expected_filecontent, "lated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure");
    strcat(expected_filecontent, " (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John XXII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exclamation on the degeneracy of human nature,\nwhich does not lift itself to the contemplation of divine things.\n\nv. 126.  The fair child of him.]  So she calls human nature.\nPindar by a more easy figure, terms the day, \"child of the sun.\"\n\nv. 129.  None.]  Because, as has been before said, the shepherds\nare become wolves.\n\nv. 131.  Before the date.]  \"Before many ages are past, before\nthose fractions, which are drops in the reckoning of every year,\nshall amount to so large a portion of time, that January shall be\nno more a winter month.\" By this periphrasis is meant \" in a\nshort time,\" as we say familiarly, such a thing will happen\nbefore a thousand years are over when we mean, it will happen\nsoon.\n\nv. 135.  Fortune shall be fain.]  The commentators in general\nsuppose that our Poet here augurs that great reform, which he\nvainly hoped would follow on the arrival of the Emperor Henry\nVII. in Italy. Lombardi refers the prognostication to Can Grande\ndella Scala: and, when we consider that this Canto was not\nfinished till after the death of  Henry, as appears from the\nmention that is made of John XXII, it cannot be denied but the\nconjecture is probable.\n\nCANTO XXVIII\n\nv. 36.  Heav\'n, and all nature, hangs upon that point.]  [GREEK\nHERE]\nAristot. Metaph. 1. xii. c. 7.  \"From that beginning depend\nheaven and nature.\"\n\nv. 43.  Such diff\'rence.]  The material world and the\nintelligential (the copy and the pattern) appear to Dante to\ndiffer in this respect, that the orbits of the latter are more\nswift, the nearer they are to the centre, whereas the contrary is\nthe case with the orbits of the former. The seeming contradiction\nis thus accounted for by Beatrice.  In the material world, the\nmore ample the body is, the greater is the good of which itis\ncapable supposing all the parts to be equally perfect. But in the\nintelligential world, the circles are more excellent and\npowerful, the more they approximate to the central point, which\nis God.  Thus the first circle, that of the seraphim, corresponds\nto the ninth sphere, or primum mobile, the second, that of the\ncherubim, to the eighth sphere, or heaven of fixed stars; the\nthird, or circle of thrones, to the seventh sphere, or planet of\nSaturn; and in like manner throughout the two other trines of\ncircles and spheres.\n\nIn orbs\nOf circuit inexpressible they stood,\nOrb within orb\nMilton, P. L. b. v. 596.\n\nv. 70.  The sturdy north.]  Compare Homer, II. b. v. 524.\n\nv. 82.  In number.]  The sparkles exceeded the number which would\nbe produced by the sixty-four squares of a chess-board, if for\nthe first we reckoned one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nigh");
    strcat(expected_filecontent, "tly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part of the\ncreation, which participates both of spirit and matter, were\nproduced at once.\n\nv. 38.  On Jerome\'s pages.]  St. Jerome had described the angels\nas created before the rest of the universe: an opinion which\nThomas  Aquinas controverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye c");
    strcat(expected_filecontent, "omm");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CATCH.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 12751, file);
                test_error(size == 12288, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12288 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12288);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 12288);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(12356, 1);
                char expected_filecontent[12357] = "";

                strcat(expected_filecontent, " him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefo");
    strcat(expected_filecontent, "re on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards u");
    strcat(expected_filecontent, "s came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer know");
    strcat(expected_filecontent, "n,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit dow");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BEHIND.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 12724, file);
                test_error(size == 12356, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12356 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12356);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 12356);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1230, 1);
                char expected_filecontent[1231] = "";

                strcat(expected_filecontent, "  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thu");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BROKELAN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1372, file);
                test_error(size == 1230, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1230 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1230);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1230);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1413] = "";

                strcat(expected_filecontent, "wrought in Scaevola\nTo his own hand remorseless, to the path,\nWhence they were drawn, their steps had hasten\'d back,\nWhen liberty return\'d: but in too few\nResolve so steadfast dwells.  And by these words\nIf duly weigh\'d, that argument is void,\nWhich oft might have perplex\'d thee still.  But now\nAnother question thwarts thee, which to solve\nMight try thy patience without better aid.\nI have, no doubt, instill\'d into thy mind,\nThat blessed spirit may not lie; since near\nThe source of primal truth it dwells for aye:\nAnd thou might\'st after of Piccarda learn\nThat Constance held affection to the veil;\nSo that she seems to contradict me here.\nNot seldom, brother, it hath chanc\'d for men\nTo do what they had gladly left undone,\nYet to shun peril they have done amiss:\nE\'en as Alcmaeon, at his father\'s suit\nSlew his own mother, so made pitiless\nNot to lose pity.  On this point bethink thee,\nThat force and will are blended in such wise\nAs not to make the\' offence excusable.\nAbsolute will agrees not to the wrong,\nThat inasmuch as there is fear of woe\nFrom non-compliance, it agrees.  Of will\nThus absolute Piccarda spake, and I\nOf th\' other; so that both have truly said.\"\n     Such was the flow of that pure rill, that well\'d\nFrom forth the fountain of all truth; and such\nThe rest, that to my wond\'ring thoughts l found.\n      \"O thou of primal love the prime delight!\nGoddess!  \"I straight reply\'d, \"whose ");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "AMONG.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1412; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[8425] = "";

                strcat(expected_filecontent, " the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total reverse of fortune should\nensue, as a punishment for his acts of treachery and guilt:  for\nhe was said to have poisoned the Count Anselmo da Capraia, his\nsister\'s son, on account of the envy and fear excited in his mind\nby the high esteem in which the gracious manners of Anselmo were\nheld by the Pisans.  The power of the Guelphi being so much\ndiminished, the Archbishop devised means to betray the Count\nUglino and caused him to be suddenly attacked in his palace by\nthe fury of the people, whom he had exasperated, by telling them\n");
    strcat(expected_filecontent, "that Ugolino had betrayed Pisa, and given up their castles to the\ncitizens of Florence and of Lucca. He was immediately compelled\nto surrender; his bastard son and his grandson fell in the\nassault; and two of his sons, with their two sons also, were\nconveyed to prison.\"  G. Villani l. vii. c. 120.\n\n\"In the following march, the Pisans, who had imprisoned the Count\nUglino, with two of his sons and two of his grandchildren, the\noffspring of his son the Count Guelfo, in a tower on the Piazza\nof the Anzania, caused the tower to be locked, the key thrown\ninto the Arno, and all food to be withheld from them.  In a few\ndays they died of hunger; but the Count first with loud cries\ndeclared his penitence, and yet neither priest nor friar was\nallowed to shrive him.  All the five, when dead, were dragged out\nof the prison, and meanly interred; and from thence forward the\ntower was called the tower of famine, and so shall ever be.\"\nIbid. c. 127.\n\nChancer has briefly told Ugolino\'s story. See Monke\'s Tale,\nHugeline of Pise.\n\nv. 29.  Unto the mountain.]  The mountain S. Giuliano, between\nPisa and Lucca.\n\nv. 59. Thou gav\'st.]\n               Tu ne vestisti\n        Queste misere carni, e tu le spoglia.\nImitated by Filicaja, Canz. iii.\n        Di questa imperial caduca spoglia\n        Tu, Signor, me vestisti e tu mi spoglia:\n        Ben puoi\'l Regno me tor tu che me\'l desti.\nAnd by Maffei, in the Merope:\n               Tu disciogleste\n        Queste misere membra e tu le annodi.\n\nv. 79. In that fair region.]\n        Del bel paese la, dove\'l si suona.\nItaly as explained by Dante himself, in his treatise De Vulg.\nEloq. l. i. c. 8. \"Qui autem Si dicunt a praedictis finibus.\n(Januensiem) Oreintalem (Meridionalis Europae partem) tenent;\nvidelicet usque ad promontorium illud Italiae, qua sinus\nAdriatici maris incipit et Siciliam.\"\n\nv. 82.  Capraia and Gorgona.]  Small islands near the mouth of\nthe Arno.\n\nv. 94.  There very weeping suffers not to weep,]\n        Lo pianto stesso li pianger non lascia.\nSo Giusto de\'Conti, Bella Mano. Son. \"Quanto il ciel.\"\n        Che il troppo pianto a me pianger non lassa.\nv. 116.  The friar Albigero.]  Alberigo de\'Manfredi, of Faenza,\none of the Frati Godenti, Joyons Friars who having quarrelled\nwith some of his brotherhood, under pretence of wishing to be\nreconciled, invited them to a banquet, at the conclusion of which\nhe called for the fruit, a signal for the assassins to rush in\nand dispatch those whom he had marked for destruction.  Hence,\nadds Landino, it is said proverbially of one who has been\nstabbed, that he has had some of the friar Alberigo\'s fruit.\nThus Pulci, Morg. Magg. c. xxv.\n        Le frutte amare di frate Alberico.\n\nv. 123.  Ptolomea.]  This circle is named Ptolomea from Ptolemy,\nthe son of Abubus, by whom Simon and his sons were murdered, at a\ngreat banquet he had made for them. See Maccabees, ch xvi.\n\nv. 126.  The glazed tear-drops.]\n\n        -sorrow\'s eye, glazed with blinding tears.\n               Shakspeare, Rich. II. a. 2. s. 2.\n\nv. 136.  Branca Doria.]  The family of Doria was possessed of\ngreat influence in Genoa.  Branca is said to have murdered his\nfather-in-law, Michel Zanche, introduced in Canto XXII.\n\nv. 162  Romagna\'s darkest spirit.]  The friar Alberigo.\n\n\n\nCanto XXXIV.\n\nv. 6.  A wind-mill.]  The author of the Caliph Vathek, in the\nnotes to that tale, justly observes, that it is more than\nprobable that Don Quixote\'s mistake of the wind-mills for giants\nwas suggested to Cervantes by this simile.\n\nv. 37. Three faces.]  It can scarcely be doubted but that Milton\nderived his description of Satan in those lines,\n\n               Each passion dimm\'d his face\n        Thrice chang\'d with pale, ire, envy, and despair.\n               P. L. b. iv. 114.\nfrom this passage, coupled with the remark of Vellutello upon it:\n\n\"The first of these sins is anger which he signifies by the red\nface; the second, represented by that between pale and yellow is\nenvy and not, as others have said, avarice; and the third,\ndenoted by the black, is a melancholy humour that causes a man\'s\nthoughts to be dark an");
    strcat(expected_filecontent, "d evil, and averse from all joy and\ntranquillity.\"\n\nv. 44. Sails.]\n               --His sail-broad vans\n        He spreads for flight.\n               Milton, P. L. b. ii. 927.\nCompare Spenser, F. Q. b. i. c. xi. st. 10;  Ben Jonson\'s ");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PROCESS.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 8424; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6596] = "";

                strcat(expected_filecontent, "ven now such aid, that to retrace your forms\nIs easier.  Yet inform me, ye, who here\nAre happy, long ye for a higher place\nMore to behold, and more in love to dwell?\"\n     She with those other spirits gently smil\'d,\nThen answer\'d with such gladness, that she seem\'d\nWith love\'s first flame to glow:  \"Brother!  our will\nIs in composure settled by the power\nOf charity, who makes us will alone\nWhat we possess, and nought beyond desire;\nIf we should wish to be exalted more,\nThen must our wishes jar with the high will\nOf him, who sets us here, which in these orbs\nThou wilt confess not possible, if here\nTo be in charity must needs befall,\nAnd if her nature well thou contemplate.\nRather it is inherent in this state\nOf blessedness, to keep ourselves within\nThe divine will, by which our wills with his\nAre one.  So that as we from step to step\nAre plac\'d throughout this kingdom, pleases all,\nE\'en as our King, who in us plants his will;\nAnd in his will is our tranquillity;\nIt is the mighty ocean, whither tends\nWhatever it creates and nature makes.\"\n     Then saw I clearly how each spot in heav\'n\nIs Paradise, though with like gracious dew\nThe supreme virtue show\'r not over all.\n     But as it chances, if one sort of food\nHath satiated, and of another still\nThe appetite remains, that this is ask\'d,\nAnd thanks for that return\'d; e\'en so did I\nIn word and motion, bent from her to learn\nWhat web it was, through which she had not drawn\nThe shuttle to its point.  She thus began:\n\"Exalted worth and perfectness of life\nThe Lady higher up enshrine in heaven,\nBy whose pure laws upon your nether earth\nThe robe and veil they wear, to that intent,\nThat e\'en till death they may keep watch or sleep\nWith their great bridegroom, who accepts each vow,\nWhich to his gracious pleasure love conforms.\nfrom the world, to follow her, when young\nEscap\'d; and, in her vesture mantling me,\nMade promise of the way her sect enjoins.\nThereafter men, for ill than good more apt,\nForth snatch\'d me from the pleasant cloister\'s pale.\nGod knows how after that my life was fram\'d.\nThis other splendid shape, which thou beholdst\nAt my right side, burning with all the light\nOf this our orb, what of myself I tell\nMay to herself apply.  From her, like me\nA sister, with like violence were torn\nThe saintly folds, that shaded her fair brows.\nE\'en when she to the world again was brought\nIn spite of her own will and better wont,\nYet not for that the bosom\'s inward veil\nDid she renounce.  This is the luminary\nOf mighty Constance, who from that loud blast,\nWhich blew the second over Suabia\'s realm,\nThat power produc\'d, which was the third and last.\"\n     She ceas\'d from further talk, and then began\n\"Ave Maria\" singing, and with that song\nVanish\'d, as heavy substance through deep wave.\n     Mine eye, that far as it was capable,\nPursued her, when in dimness she was lost,\nTurn\'d to the mark where greater want impell\'d,\nAnd bent on Beatrice all its gaze.\nBut she as light\'ning beam\'d upon my looks:\nSo that the sight sustain\'d it not at first.\nWhence I to question her became less prompt.\n\n\n\nCANTO IV\n\nBetween two kinds of food, both equally\nRemote and tempting, first a man might die\nOf hunger, ere he one could freely choose.\nE\'en so would stand a lamb between the maw\nOf two fierce wolves, in dread of both alike:\nE\'en so between two deer a dog would stand,\nWherefore, if I was silent, fault nor praise\nI to myself impute, by equal doubts\nHeld in suspense, since of necessity\nIt happen\'d.  Silent was I, yet desire\nWas painted in my looks; and thus I spake\nMy wish more earnestly than language could.\n     As Daniel, when the haughty king he freed\nFrom ire, that spurr\'d him on to deeds unjust\nAnd violent; so look\'d Beatrice then.\n     \"Well I discern,\" she thus her words address\'d,\n\"How contrary desires each way constrain thee,\nSo that thy anxious thought is in itself\nBound up and stifled, nor breathes freely forth.\nThou arguest; if the good intent remain;\nWhat reason that another\'s violence\nShould stint the measure of my fair desert?\n     \"Cause too thou findst for doubt, in that it seems,\nThat sp");
    strcat(expected_filecontent, "irits to the stars, as Plato deem\'d,\nReturn.  These are the questions which thy will\nUrge equally; and therefore I the first\nOf that will treat which hath the more of gall.\nOf seraphim he who is most ensky\'d,\nMoses and Samuel, and either John,\nChoose which thou wilt, nor even Mary\'s self,\nHave not in any other heav\'n their seats,\nThan have those spirits which so late thou saw\'st;\nNor more or fewer years exist; but all\nMake the first circle beauteous, diversely\nPartaking of sweet life, as more or less\nAfflation of eternal bliss pervades them.\nHere were they shown thee, not that fate assigns\nThis for their sphere, but for a sign to thee\nOf that celestial furthest from the height.\nThus needs, that ye may apprehend, we speak:\nSince from things sensible alone ye learn\nThat, which digested rightly after turns\nTo intellectual.  For no other cause\nThe scripture, condescending graciously\nTo your perception, hands and feet to God\nAttributes, nor so means: and holy church\nDoth represent with human countenance\nGabriel, and Michael, and him who made\nTobias whole.  Unlike what here thou seest,\nThe judgment of Timaeus, who affirms\nEach soul restor\'d to its particular star,\nBelieving it to have been taken thence,\nWhen nature gave it to inform her mold:\nSince to appearance his intention is\nE\'en what his words declare: or else to shun\nDerision, haply thus he hath disguis\'d\nHis true opinion.  If his meaning be,\nThat to the influencing of these orbs revert\nThe honour and the blame in human acts,\nPerchance he doth not wholly miss the truth.\nThis principle, not understood aright,\nErewhile perverted well nigh all the world;\nSo that it fell to fabled names of Jove,\nAnd Mercury, and Mars.  That other doubt,\nWhich moves thee, is less harmful; for it brings\nNo peril of removing thee from me.\n     \"That, to the eye of man, our justice seems\nUnjust, is argument for faith, and not\nFor heretic declension.  To the end\nThis truth may stand more clearly in your view,\nI will content thee even to thy wish\n     \"If violence be, when that which suffers, nought\nConsents to that which forceth, not for this\nThese spirits stood exculpate.  For the will,\nThat will not, still survives unquench\'d, and doth\nAs nature doth in fire, tho\' violence\nWrest it a thousand times; for, if it yield\nOr more or less, so far it follows force.\nAnd thus did these, whom they had power to seek\nThe hallow\'d place again.  In them, had will\nBeen perfect, such as once upon the bars\nHeld Laurence firm, or wrought in Scaevol");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SEND");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6595; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6531] = "";

                strcat(expected_filecontent, " pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nTh");
    strcat(expected_filecontent, "e grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWer");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ROW");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6530; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[12289] = "";

                strcat(expected_filecontent, "lated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure");
    strcat(expected_filecontent, " (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John XXII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exclamation on the degeneracy of human nature,\nwhich does not lift itself to the contemplation of divine things.\n\nv. 126.  The fair child of him.]  So she calls human nature.\nPindar by a more easy figure, terms the day, \"child of the sun.\"\n\nv. 129.  None.]  Because, as has been before said, the shepherds\nare become wolves.\n\nv. 131.  Before the date.]  \"Before many ages are past, before\nthose fractions, which are drops in the reckoning of every year,\nshall amount to so large a portion of time, that January shall be\nno more a winter month.\" By this periphrasis is meant \" in a\nshort time,\" as we say familiarly, such a thing will happen\nbefore a thousand years are over when we mean, it will happen\nsoon.\n\nv. 135.  Fortune shall be fain.]  The commentators in general\nsuppose that our Poet here augurs that great reform, which he\nvainly hoped would follow on the arrival of the Emperor Henry\nVII. in Italy. Lombardi refers the prognostication to Can Grande\ndella Scala: and, when we consider that this Canto was not\nfinished till after the death of  Henry, as appears from the\nmention that is made of John XXII, it cannot be denied but the\nconjecture is probable.\n\nCANTO XXVIII\n\nv. 36.  Heav\'n, and all nature, hangs upon that point.]  [GREEK\nHERE]\nAristot. Metaph. 1. xii. c. 7.  \"From that beginning depend\nheaven and nature.\"\n\nv. 43.  Such diff\'rence.]  The material world and the\nintelligential (the copy and the pattern) appear to Dante to\ndiffer in this respect, that the orbits of the latter are more\nswift, the nearer they are to the centre, whereas the contrary is\nthe case with the orbits of the former. The seeming contradiction\nis thus accounted for by Beatrice.  In the material world, the\nmore ample the body is, the greater is the good of which itis\ncapable supposing all the parts to be equally perfect. But in the\nintelligential world, the circles are more excellent and\npowerful, the more they approximate to the central point, which\nis God.  Thus the first circle, that of the seraphim, corresponds\nto the ninth sphere, or primum mobile, the second, that of the\ncherubim, to the eighth sphere, or heaven of fixed stars; the\nthird, or circle of thrones, to the seventh sphere, or planet of\nSaturn; and in like manner throughout the two other trines of\ncircles and spheres.\n\nIn orbs\nOf circuit inexpressible they stood,\nOrb within orb\nMilton, P. L. b. v. 596.\n\nv. 70.  The sturdy north.]  Compare Homer, II. b. v. 524.\n\nv. 82.  In number.]  The sparkles exceeded the number which would\nbe produced by the sixty-four squares of a chess-board, if for\nthe first we reckoned one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nigh");
    strcat(expected_filecontent, "tly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part of the\ncreation, which participates both of spirit and matter, were\nproduced at once.\n\nv. 38.  On Jerome\'s pages.]  St. Jerome had described the angels\nas created before the rest of the universe: an opinion which\nThomas  Aquinas controverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye c");
    strcat(expected_filecontent, "omm");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CATCH.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 12288; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[12357] = "";

                strcat(expected_filecontent, " him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefo");
    strcat(expected_filecontent, "re on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards u");
    strcat(expected_filecontent, "s came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer know");
    strcat(expected_filecontent, "n,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit dow");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BEHIND.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 12356; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1231] = "";

                strcat(expected_filecontent, "  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thu");

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BROKELAN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1230; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(6530, 1);
            char expected_filecontent[6531] = "";

            strcat(expected_filecontent, " pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nTh");
    strcat(expected_filecontent, "e grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWer");

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "ROW");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 1632; ++i)
            {
                int res = file_read(filecontent + 4 * i, 4, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 4 * i, 4, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6530);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 6530);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(1412, 1);
    char *filecontent1 = (char *)calloc(8424, 1);
    char *filecontent2 = (char *)calloc(6595, 1);
    char *filecontent3 = (char *)calloc(6530, 1);
    char *filecontent4 = (char *)calloc(12288, 1);
    char *filecontent5 = (char *)calloc(12356, 1);
    char *filecontent6 = (char *)calloc(1230, 1);

            char expected_filecontent0[1413] = "";
    char expected_filecontent1[8425] = "";
    char expected_filecontent2[6596] = "";
    char expected_filecontent3[6531] = "";
    char expected_filecontent4[12289] = "";
    char expected_filecontent5[12357] = "";
    char expected_filecontent6[1231] = "";

            strcat(expected_filecontent0, "wrought in Scaevola\nTo his own hand remorseless, to the path,\nWhence they were drawn, their steps had hasten\'d back,\nWhen liberty return\'d: but in too few\nResolve so steadfast dwells.  And by these words\nIf duly weigh\'d, that argument is void,\nWhich oft might have perplex\'d thee still.  But now\nAnother question thwarts thee, which to solve\nMight try thy patience without better aid.\nI have, no doubt, instill\'d into thy mind,\nThat blessed spirit may not lie; since near\nThe source of primal truth it dwells for aye:\nAnd thou might\'st after of Piccarda learn\nThat Constance held affection to the veil;\nSo that she seems to contradict me here.\nNot seldom, brother, it hath chanc\'d for men\nTo do what they had gladly left undone,\nYet to shun peril they have done amiss:\nE\'en as Alcmaeon, at his father\'s suit\nSlew his own mother, so made pitiless\nNot to lose pity.  On this point bethink thee,\nThat force and will are blended in such wise\nAs not to make the\' offence excusable.\nAbsolute will agrees not to the wrong,\nThat inasmuch as there is fear of woe\nFrom non-compliance, it agrees.  Of will\nThus absolute Piccarda spake, and I\nOf th\' other; so that both have truly said.\"\n     Such was the flow of that pure rill, that well\'d\nFrom forth the fountain of all truth; and such\nThe rest, that to my wond\'ring thoughts l found.\n      \"O thou of primal love the prime delight!\nGoddess!  \"I straight reply\'d, \"whose ");strcat(expected_filecontent1, " the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total reverse of fortune should\nensue, as a punishment for his acts of treachery and guilt:  for\nhe was said to have poisoned the Count Anselmo da Capraia, his\nsister\'s son, on account of the envy and fear excited in his mind\nby the high esteem in which the gracious manners of Anselmo were\nheld by the Pisans.  The power of the Guelphi being so much\ndiminished, the Archbishop devised means to betray the Count\nUglino and caused him to be suddenly attacked in his palace by\nthe fury of the people, whom he had exasperated, by telling them\n");
    strcat(expected_filecontent1, "that Ugolino had betrayed Pisa, and given up their castles to the\ncitizens of Florence and of Lucca. He was immediately compelled\nto surrender; his bastard son and his grandson fell in the\nassault; and two of his sons, with their two sons also, were\nconveyed to prison.\"  G. Villani l. vii. c. 120.\n\n\"In the following march, the Pisans, who had imprisoned the Count\nUglino, with two of his sons and two of his grandchildren, the\noffspring of his son the Count Guelfo, in a tower on the Piazza\nof the Anzania, caused the tower to be locked, the key thrown\ninto the Arno, and all food to be withheld from them.  In a few\ndays they died of hunger; but the Count first with loud cries\ndeclared his penitence, and yet neither priest nor friar was\nallowed to shrive him.  All the five, when dead, were dragged out\nof the prison, and meanly interred; and from thence forward the\ntower was called the tower of famine, and so shall ever be.\"\nIbid. c. 127.\n\nChancer has briefly told Ugolino\'s story. See Monke\'s Tale,\nHugeline of Pise.\n\nv. 29.  Unto the mountain.]  The mountain S. Giuliano, between\nPisa and Lucca.\n\nv. 59. Thou gav\'st.]\n               Tu ne vestisti\n        Queste misere carni, e tu le spoglia.\nImitated by Filicaja, Canz. iii.\n        Di questa imperial caduca spoglia\n        Tu, Signor, me vestisti e tu mi spoglia:\n        Ben puoi\'l Regno me tor tu che me\'l desti.\nAnd by Maffei, in the Merope:\n               Tu disciogleste\n        Queste misere membra e tu le annodi.\n\nv. 79. In that fair region.]\n        Del bel paese la, dove\'l si suona.\nItaly as explained by Dante himself, in his treatise De Vulg.\nEloq. l. i. c. 8. \"Qui autem Si dicunt a praedictis finibus.\n(Januensiem) Oreintalem (Meridionalis Europae partem) tenent;\nvidelicet usque ad promontorium illud Italiae, qua sinus\nAdriatici maris incipit et Siciliam.\"\n\nv. 82.  Capraia and Gorgona.]  Small islands near the mouth of\nthe Arno.\n\nv. 94.  There very weeping suffers not to weep,]\n        Lo pianto stesso li pianger non lascia.\nSo Giusto de\'Conti, Bella Mano. Son. \"Quanto il ciel.\"\n        Che il troppo pianto a me pianger non lassa.\nv. 116.  The friar Albigero.]  Alberigo de\'Manfredi, of Faenza,\none of the Frati Godenti, Joyons Friars who having quarrelled\nwith some of his brotherhood, under pretence of wishing to be\nreconciled, invited them to a banquet, at the conclusion of which\nhe called for the fruit, a signal for the assassins to rush in\nand dispatch those whom he had marked for destruction.  Hence,\nadds Landino, it is said proverbially of one who has been\nstabbed, that he has had some of the friar Alberigo\'s fruit.\nThus Pulci, Morg. Magg. c. xxv.\n        Le frutte amare di frate Alberico.\n\nv. 123.  Ptolomea.]  This circle is named Ptolomea from Ptolemy,\nthe son of Abubus, by whom Simon and his sons were murdered, at a\ngreat banquet he had made for them. See Maccabees, ch xvi.\n\nv. 126.  The glazed tear-drops.]\n\n        -sorrow\'s eye, glazed with blinding tears.\n               Shakspeare, Rich. II. a. 2. s. 2.\n\nv. 136.  Branca Doria.]  The family of Doria was possessed of\ngreat influence in Genoa.  Branca is said to have murdered his\nfather-in-law, Michel Zanche, introduced in Canto XXII.\n\nv. 162  Romagna\'s darkest spirit.]  The friar Alberigo.\n\n\n\nCanto XXXIV.\n\nv. 6.  A wind-mill.]  The author of the Caliph Vathek, in the\nnotes to that tale, justly observes, that it is more than\nprobable that Don Quixote\'s mistake of the wind-mills for giants\nwas suggested to Cervantes by this simile.\n\nv. 37. Three faces.]  It can scarcely be doubted but that Milton\nderived his description of Satan in those lines,\n\n               Each passion dimm\'d his face\n        Thrice chang\'d with pale, ire, envy, and despair.\n               P. L. b. iv. 114.\nfrom this passage, coupled with the remark of Vellutello upon it:\n\n\"The first of these sins is anger which he signifies by the red\nface; the second, represented by that between pale and yellow is\nenvy and not, as others have said, avarice; and the third,\ndenoted by the black, is a melancholy humour that causes a man\'s\nthoughts to be dark an");
    strcat(expected_filecontent1, "d evil, and averse from all joy and\ntranquillity.\"\n\nv. 44. Sails.]\n               --His sail-broad vans\n        He spreads for flight.\n               Milton, P. L. b. ii. 927.\nCompare Spenser, F. Q. b. i. c. xi. st. 10;  Ben Jonson\'s ");strcat(expected_filecontent2, "ven now such aid, that to retrace your forms\nIs easier.  Yet inform me, ye, who here\nAre happy, long ye for a higher place\nMore to behold, and more in love to dwell?\"\n     She with those other spirits gently smil\'d,\nThen answer\'d with such gladness, that she seem\'d\nWith love\'s first flame to glow:  \"Brother!  our will\nIs in composure settled by the power\nOf charity, who makes us will alone\nWhat we possess, and nought beyond desire;\nIf we should wish to be exalted more,\nThen must our wishes jar with the high will\nOf him, who sets us here, which in these orbs\nThou wilt confess not possible, if here\nTo be in charity must needs befall,\nAnd if her nature well thou contemplate.\nRather it is inherent in this state\nOf blessedness, to keep ourselves within\nThe divine will, by which our wills with his\nAre one.  So that as we from step to step\nAre plac\'d throughout this kingdom, pleases all,\nE\'en as our King, who in us plants his will;\nAnd in his will is our tranquillity;\nIt is the mighty ocean, whither tends\nWhatever it creates and nature makes.\"\n     Then saw I clearly how each spot in heav\'n\nIs Paradise, though with like gracious dew\nThe supreme virtue show\'r not over all.\n     But as it chances, if one sort of food\nHath satiated, and of another still\nThe appetite remains, that this is ask\'d,\nAnd thanks for that return\'d; e\'en so did I\nIn word and motion, bent from her to learn\nWhat web it was, through which she had not drawn\nThe shuttle to its point.  She thus began:\n\"Exalted worth and perfectness of life\nThe Lady higher up enshrine in heaven,\nBy whose pure laws upon your nether earth\nThe robe and veil they wear, to that intent,\nThat e\'en till death they may keep watch or sleep\nWith their great bridegroom, who accepts each vow,\nWhich to his gracious pleasure love conforms.\nfrom the world, to follow her, when young\nEscap\'d; and, in her vesture mantling me,\nMade promise of the way her sect enjoins.\nThereafter men, for ill than good more apt,\nForth snatch\'d me from the pleasant cloister\'s pale.\nGod knows how after that my life was fram\'d.\nThis other splendid shape, which thou beholdst\nAt my right side, burning with all the light\nOf this our orb, what of myself I tell\nMay to herself apply.  From her, like me\nA sister, with like violence were torn\nThe saintly folds, that shaded her fair brows.\nE\'en when she to the world again was brought\nIn spite of her own will and better wont,\nYet not for that the bosom\'s inward veil\nDid she renounce.  This is the luminary\nOf mighty Constance, who from that loud blast,\nWhich blew the second over Suabia\'s realm,\nThat power produc\'d, which was the third and last.\"\n     She ceas\'d from further talk, and then began\n\"Ave Maria\" singing, and with that song\nVanish\'d, as heavy substance through deep wave.\n     Mine eye, that far as it was capable,\nPursued her, when in dimness she was lost,\nTurn\'d to the mark where greater want impell\'d,\nAnd bent on Beatrice all its gaze.\nBut she as light\'ning beam\'d upon my looks:\nSo that the sight sustain\'d it not at first.\nWhence I to question her became less prompt.\n\n\n\nCANTO IV\n\nBetween two kinds of food, both equally\nRemote and tempting, first a man might die\nOf hunger, ere he one could freely choose.\nE\'en so would stand a lamb between the maw\nOf two fierce wolves, in dread of both alike:\nE\'en so between two deer a dog would stand,\nWherefore, if I was silent, fault nor praise\nI to myself impute, by equal doubts\nHeld in suspense, since of necessity\nIt happen\'d.  Silent was I, yet desire\nWas painted in my looks; and thus I spake\nMy wish more earnestly than language could.\n     As Daniel, when the haughty king he freed\nFrom ire, that spurr\'d him on to deeds unjust\nAnd violent; so look\'d Beatrice then.\n     \"Well I discern,\" she thus her words address\'d,\n\"How contrary desires each way constrain thee,\nSo that thy anxious thought is in itself\nBound up and stifled, nor breathes freely forth.\nThou arguest; if the good intent remain;\nWhat reason that another\'s violence\nShould stint the measure of my fair desert?\n     \"Cause too thou findst for doubt, in that it seems,\nThat sp");
    strcat(expected_filecontent2, "irits to the stars, as Plato deem\'d,\nReturn.  These are the questions which thy will\nUrge equally; and therefore I the first\nOf that will treat which hath the more of gall.\nOf seraphim he who is most ensky\'d,\nMoses and Samuel, and either John,\nChoose which thou wilt, nor even Mary\'s self,\nHave not in any other heav\'n their seats,\nThan have those spirits which so late thou saw\'st;\nNor more or fewer years exist; but all\nMake the first circle beauteous, diversely\nPartaking of sweet life, as more or less\nAfflation of eternal bliss pervades them.\nHere were they shown thee, not that fate assigns\nThis for their sphere, but for a sign to thee\nOf that celestial furthest from the height.\nThus needs, that ye may apprehend, we speak:\nSince from things sensible alone ye learn\nThat, which digested rightly after turns\nTo intellectual.  For no other cause\nThe scripture, condescending graciously\nTo your perception, hands and feet to God\nAttributes, nor so means: and holy church\nDoth represent with human countenance\nGabriel, and Michael, and him who made\nTobias whole.  Unlike what here thou seest,\nThe judgment of Timaeus, who affirms\nEach soul restor\'d to its particular star,\nBelieving it to have been taken thence,\nWhen nature gave it to inform her mold:\nSince to appearance his intention is\nE\'en what his words declare: or else to shun\nDerision, haply thus he hath disguis\'d\nHis true opinion.  If his meaning be,\nThat to the influencing of these orbs revert\nThe honour and the blame in human acts,\nPerchance he doth not wholly miss the truth.\nThis principle, not understood aright,\nErewhile perverted well nigh all the world;\nSo that it fell to fabled names of Jove,\nAnd Mercury, and Mars.  That other doubt,\nWhich moves thee, is less harmful; for it brings\nNo peril of removing thee from me.\n     \"That, to the eye of man, our justice seems\nUnjust, is argument for faith, and not\nFor heretic declension.  To the end\nThis truth may stand more clearly in your view,\nI will content thee even to thy wish\n     \"If violence be, when that which suffers, nought\nConsents to that which forceth, not for this\nThese spirits stood exculpate.  For the will,\nThat will not, still survives unquench\'d, and doth\nAs nature doth in fire, tho\' violence\nWrest it a thousand times; for, if it yield\nOr more or less, so far it follows force.\nAnd thus did these, whom they had power to seek\nThe hallow\'d place again.  In them, had will\nBeen perfect, such as once upon the bars\nHeld Laurence firm, or wrought in Scaevol");strcat(expected_filecontent3, " pen,\nWhen Prague shall mourn her desolated realm.\nThere shall be read the woe, that he doth work\nWith his adulterate money on the Seine,\nWho by the tusk will perish: there be read\nThe thirsting pride, that maketh fool alike\nThe English and Scot, impatient of their bound.\nThere shall be seen the Spaniard\'s luxury,\nThe delicate living there of the Bohemian,\nWho still to worth has been a willing stranger.\nThe halter of Jerusalem shall see\nA unit for his virtue, for his vices\nNo less a mark than million.  He, who guards\nThe isle of fire by old Anchises honour\'d\nShall find his avarice there and cowardice;\nAnd better to denote his littleness,\nThe writing must be letters maim\'d, that speak\nMuch in a narrow space.  All there shall know\nHis uncle and his brother\'s filthy doings,\nWho so renown\'d a nation and two crowns\nHave bastardized.  And they, of Portugal\nAnd Norway, there shall be expos\'d with him\nOf Ratza, who hath counterfeited ill\nThe coin of Venice.  O blest Hungary!\nIf thou no longer patiently abid\'st\nThy ill-entreating!  and, O blest Navarre!\nIf with thy mountainous girdle thou wouldst arm thee\nIn earnest of that day, e\'en now are heard\nWailings and groans in Famagosta\'s streets\nAnd Nicosia\'s, grudging at their beast,\nWho keepeth even footing with the rest.\"\n\n\n\nCANTO XX\n\nWhen, disappearing, from our hemisphere,\nThe world\'s enlightener vanishes, and day\nOn all sides wasteth, suddenly the sky,\nErewhile irradiate only with his beam,\nIs yet again unfolded, putting forth\nInnumerable lights wherein one shines.\nOf such vicissitude in heaven I thought,\nAs the great sign, that marshaleth the world\nAnd the world\'s leaders, in the blessed beak\nWas silent; for that all those living lights,\nWaxing in splendour, burst forth into songs,\nSuch as from memory glide and fall away.\n     Sweet love!  that dost apparel thee in smiles,\nHow lustrous was thy semblance in those sparkles,\nWhich merely are from holy thoughts inspir\'d!\n     After the precious and bright beaming stones,\nThat did ingem the sixth light, ceas\'d the chiming\nOf their angelic bells; methought I heard\nThe murmuring of a river, that doth fall\nFrom rock to rock transpicuous, making known\nThe richness of his spring-head: and as sound\nOf cistern, at the fret-board, or of pipe,\nIs, at the wind-hole, modulate and tun\'d;\nThus up the neck, as it were hollow, rose\nThat murmuring of the eagle, and forthwith\nVoice there assum\'d, and thence along the beak\nIssued in form of words, such as my heart\nDid look for, on whose tables I inscrib\'d them.\n     \"The part in me, that sees, and bears the sun,,\nIn mortal eagles,\" it began, \"must now\nBe noted steadfastly: for of the fires,\nThat figure me, those, glittering in mine eye,\nAre chief of all the greatest.  This, that shines\nMidmost for pupil, was the same, who sang\nThe Holy Spirit\'s song, and bare about\nThe ark from town to town; now doth he know\nThe merit of his soul-impassion\'d strains\nBy their well-fitted guerdon.  Of the five,\nThat make the circle of the vision, he\nWho to the beak is nearest, comforted\nThe widow for her son: now doth he know\nHow dear he costeth not to follow Christ,\nBoth from experience of this pleasant life,\nAnd of its opposite.  He next, who follows\nIn the circumference, for the over arch,\nBy true repenting slack\'d the pace of death:\nNow knoweth he, that the degrees of heav\'n\nAlter not, when through pious prayer below\nToday\'s is made tomorrow\'s destiny.\nThe other following, with the laws and me,\nTo yield the shepherd room, pass\'d o\'er to Greece,\nFrom good intent producing evil fruit:\nNow knoweth he, how all the ill, deriv\'d\nFrom his well doing, doth not helm him aught,\nThough it have brought destruction on the world.\nThat, which thou seest in the under bow,\nWas William, whom that land bewails, which weeps\nFor Charles and Frederick living: now he knows\nHow well is lov\'d in heav\'n the righteous king,\nWhich he betokens by his radiant seeming.\nWho in the erring world beneath would deem,\nThat Trojan Ripheus in this round was set\nFifth of the saintly splendours?  now he knows\nEnough of that, which the world cannot see,\nTh");
    strcat(expected_filecontent3, "e grace divine, albeit e\'en his sight\nReach not its utmost depth.\"  Like to the lark,\nThat warbling in the air expatiates long,\nThen, trilling out his last sweet melody,\nDrops satiate with the sweetness; such appear\'d\nThat image stampt by the\' everlasting pleasure,\nWhich fashions like itself all lovely things.\n     I, though my doubting were as manifest,\nAs is through glass the hue that mantles it,\nIn silence waited not: for to my lips\n\"What things are these?\"  involuntary rush\'d,\nAnd forc\'d a passage out: whereat I mark\'d\nA sudden lightening and new revelry.\nThe eye was kindled: and the blessed sign\nNo more to keep me wond\'ring and suspense,\nReplied:  \"I see that thou believ\'st these things,\nBecause I tell them, but discern\'st not how;\nSo that thy knowledge waits not on thy faith:\nAs one who knows the name of thing by rote,\nBut is a stranger to its properties,\nTill other\'s tongue reveal them.  Fervent love\nAnd lively hope with violence assail\nThe kingdom of the heavens, and overcome\nThe will of the Most high; not in such sort\nAs man prevails o\'er man; but conquers it,\nBecause \'t is willing to be conquer\'d, still,\nThough conquer\'d, by its mercy conquering.\n     \"Those, in the eye who live the first and fifth,\nCause thee to marvel, in that thou behold\'st\nThe region of the angels deck\'d with them.\nThey quitted not their bodies, as thou deem\'st,\nGentiles but Christians, in firm rooted faith,\nThis of the feet in future to be pierc\'d,\nThat of feet nail\'d already to the cross.\nOne from the barrier of the dark abyss,\nWhere never any with good will returns,\nCame back unto his bones.  Of lively hope\nSuch was the meed; of lively hope, that wing\'d\nThe prayers sent up to God for his release,\nAnd put power into them to bend his will.\nThe glorious Spirit, of whom I speak to thee,\nA little while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWer");strcat(expected_filecontent4, "lated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure");
    strcat(expected_filecontent4, " (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John XXII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exclamation on the degeneracy of human nature,\nwhich does not lift itself to the contemplation of divine things.\n\nv. 126.  The fair child of him.]  So she calls human nature.\nPindar by a more easy figure, terms the day, \"child of the sun.\"\n\nv. 129.  None.]  Because, as has been before said, the shepherds\nare become wolves.\n\nv. 131.  Before the date.]  \"Before many ages are past, before\nthose fractions, which are drops in the reckoning of every year,\nshall amount to so large a portion of time, that January shall be\nno more a winter month.\" By this periphrasis is meant \" in a\nshort time,\" as we say familiarly, such a thing will happen\nbefore a thousand years are over when we mean, it will happen\nsoon.\n\nv. 135.  Fortune shall be fain.]  The commentators in general\nsuppose that our Poet here augurs that great reform, which he\nvainly hoped would follow on the arrival of the Emperor Henry\nVII. in Italy. Lombardi refers the prognostication to Can Grande\ndella Scala: and, when we consider that this Canto was not\nfinished till after the death of  Henry, as appears from the\nmention that is made of John XXII, it cannot be denied but the\nconjecture is probable.\n\nCANTO XXVIII\n\nv. 36.  Heav\'n, and all nature, hangs upon that point.]  [GREEK\nHERE]\nAristot. Metaph. 1. xii. c. 7.  \"From that beginning depend\nheaven and nature.\"\n\nv. 43.  Such diff\'rence.]  The material world and the\nintelligential (the copy and the pattern) appear to Dante to\ndiffer in this respect, that the orbits of the latter are more\nswift, the nearer they are to the centre, whereas the contrary is\nthe case with the orbits of the former. The seeming contradiction\nis thus accounted for by Beatrice.  In the material world, the\nmore ample the body is, the greater is the good of which itis\ncapable supposing all the parts to be equally perfect. But in the\nintelligential world, the circles are more excellent and\npowerful, the more they approximate to the central point, which\nis God.  Thus the first circle, that of the seraphim, corresponds\nto the ninth sphere, or primum mobile, the second, that of the\ncherubim, to the eighth sphere, or heaven of fixed stars; the\nthird, or circle of thrones, to the seventh sphere, or planet of\nSaturn; and in like manner throughout the two other trines of\ncircles and spheres.\n\nIn orbs\nOf circuit inexpressible they stood,\nOrb within orb\nMilton, P. L. b. v. 596.\n\nv. 70.  The sturdy north.]  Compare Homer, II. b. v. 524.\n\nv. 82.  In number.]  The sparkles exceeded the number which would\nbe produced by the sixty-four squares of a chess-board, if for\nthe first we reckoned one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nigh");
    strcat(expected_filecontent4, "tly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part of the\ncreation, which participates both of spirit and matter, were\nproduced at once.\n\nv. 38.  On Jerome\'s pages.]  St. Jerome had described the angels\nas created before the rest of the universe: an opinion which\nThomas  Aquinas controverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye c");
    strcat(expected_filecontent4, "omm");strcat(expected_filecontent5, " him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefo");
    strcat(expected_filecontent5, "re on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards u");
    strcat(expected_filecontent5, "s came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer know");
    strcat(expected_filecontent5, "n,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit dow");strcat(expected_filecontent6, "  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thu");


            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "AMONG.TX");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "PROCESS.BIN");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "SEND");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "ROW");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "CATCH.TX");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "BEHIND.BIN");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "BROKELAN");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 1412, file0);
                test_error(size0 == 1412, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1412 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 1412);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 1412);
            
                size_t size1 = file_read(filecontent1, 1, 8424, file1);
                test_error(size1 == 8424, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 8424 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 8424);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 8424);
            
                size_t size2 = file_read(filecontent2, 1, 6595, file2);
                test_error(size2 == 6595, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6595 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 6595);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 6595);
            
                size_t size3 = file_read(filecontent3, 1, 6530, file3);
                test_error(size3 == 6530, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6530 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 6530);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 6530);
            
                size_t size4 = file_read(filecontent4, 1, 12288, file4);
                test_error(size4 == 12288, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12288 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 12288);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 12288);
            
                size_t size5 = file_read(filecontent5, 1, 12356, file5);
                test_error(size5 == 12356, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12356 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 12356);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 12356);
            
                size_t size6 = file_read(filecontent6, 1, 1230, file6);
                test_error(size6 == 1230, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1230 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 1230);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 1230);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(12288, 1);
            char expected_filecontent[12289] = "";

            strcat(expected_filecontent, "lated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.]  St. Peter\' who looked as the planet Jupiter\nwould, if it assumed the sanguine appearance of liars.\n\nv. 20.  He.]  Boniface VIII.\n\nv. 26.  such colour.]\nQui color infectis adversi solis ab ietu\nNubibus esse solet; aut purpureae Aurorae.\nOvid, Met.  1. iii. 184.\n\nv. 37.  Of Linus and of Cletus.]  Bishops of Rome in the first\ncentury.\n\nv. 40.  Did Sextus, Pius, and Callixtus bleed\nAnd Urban.]\nThe former two, bishops of the same see, in the second; and the\nothers, in the fourth century.\nv. 42.  No purpose was of ours.]  \"We did not intend that our\nsuccessors should take any part in the political divisions among\nChristians, or that my figure");
    strcat(expected_filecontent, " (the seal of St. Peter) should\nserve as a mark to authorize iniquitous grants and privileges.\"\n\nv. 51.  Wolves.]  Compare Milton, P. L. b. xii. 508, &c.\n\nv. 53.  Cahorsines and Gascons.]  He alludes to Jacques d\'Ossa, a\nnative of Cahors, who filled the papal chair in 1316, after it\nhad been two years vacant, and assumed the name of John XXII.,\nand to Clement V, a Gascon, of whom see Hell, Canto XIX. 86, and\nNote.\n\nv. 63.  The she-goat.]  When the sun is in Capricorn.\n\nv. 72.  From the hour.]  Since he had last looked (see Canto\nXXII.) he perceived that he had passed from the meridian circle\nto the eastern horizon, the half of our hemisphere, and a quarter\nof the heaven.\n\nv. 76.  From Gades.]  See Hell, Canto XXVI. 106\n\nv. 78.  The shore.]  Phoenicia, where Europa, the daughter of\nAgenor mounted on the back of Jupiter, in his shape of a bull.\n\nv. 80.  The sun.]  Dante was in the constellation Gemini, and the\nsun  in Aries.  There was, therefore, part of those two\nconstellations, and the whole of Taurus, between them.\n\nv. 93.  The fair nest of Leda.]  \"From the Gemini;\" thus called,\nbecause Leda was the mother of the twins, Castor and Pollux\n\nv. 112.  Time\'s roots.]  \"Here,\" says Beatrice, \"are the roots,\nfrom whence time springs: for the parts, into which it is\ndivided, the other heavens must be considered.\"  And she then\nbreaks out into an exclamation on the degeneracy of human nature,\nwhich does not lift itself to the contemplation of divine things.\n\nv. 126.  The fair child of him.]  So she calls human nature.\nPindar by a more easy figure, terms the day, \"child of the sun.\"\n\nv. 129.  None.]  Because, as has been before said, the shepherds\nare become wolves.\n\nv. 131.  Before the date.]  \"Before many ages are past, before\nthose fractions, which are drops in the reckoning of every year,\nshall amount to so large a portion of time, that January shall be\nno more a winter month.\" By this periphrasis is meant \" in a\nshort time,\" as we say familiarly, such a thing will happen\nbefore a thousand years are over when we mean, it will happen\nsoon.\n\nv. 135.  Fortune shall be fain.]  The commentators in general\nsuppose that our Poet here augurs that great reform, which he\nvainly hoped would follow on the arrival of the Emperor Henry\nVII. in Italy. Lombardi refers the prognostication to Can Grande\ndella Scala: and, when we consider that this Canto was not\nfinished till after the death of  Henry, as appears from the\nmention that is made of John XXII, it cannot be denied but the\nconjecture is probable.\n\nCANTO XXVIII\n\nv. 36.  Heav\'n, and all nature, hangs upon that point.]  [GREEK\nHERE]\nAristot. Metaph. 1. xii. c. 7.  \"From that beginning depend\nheaven and nature.\"\n\nv. 43.  Such diff\'rence.]  The material world and the\nintelligential (the copy and the pattern) appear to Dante to\ndiffer in this respect, that the orbits of the latter are more\nswift, the nearer they are to the centre, whereas the contrary is\nthe case with the orbits of the former. The seeming contradiction\nis thus accounted for by Beatrice.  In the material world, the\nmore ample the body is, the greater is the good of which itis\ncapable supposing all the parts to be equally perfect. But in the\nintelligential world, the circles are more excellent and\npowerful, the more they approximate to the central point, which\nis God.  Thus the first circle, that of the seraphim, corresponds\nto the ninth sphere, or primum mobile, the second, that of the\ncherubim, to the eighth sphere, or heaven of fixed stars; the\nthird, or circle of thrones, to the seventh sphere, or planet of\nSaturn; and in like manner throughout the two other trines of\ncircles and spheres.\n\nIn orbs\nOf circuit inexpressible they stood,\nOrb within orb\nMilton, P. L. b. v. 596.\n\nv. 70.  The sturdy north.]  Compare Homer, II. b. v. 524.\n\nv. 82.  In number.]  The sparkles exceeded the number which would\nbe produced by the sixty-four squares of a chess-board, if for\nthe first we reckoned one, for the next, two; for the third,\nfour; and so went on doubling to the end of the account.\n\nv. 106.  Fearless of bruising from the nigh");
    strcat(expected_filecontent, "tly ram.]  Not\ninjured, like the productions of our spring, by the influence of\nautumn, when the constellation Aries rises at sunset.\n\nv. 110.  Dominations.]\nHear all ye angels, progeny of light,\nThrones, domination\'s, princedoms, virtues, powers.\nMilton, P. L. b. v. 601.\n\nv. 119.  Dionysius.]  The Areopagite, in his book De Caelesti\nHierarchia.\n\nv. 124.  Gregory.]  Gregory the Great.  \"Novem vero angelorum\nordines diximus, quia videlicet esse, testante sacro eloquio,\nscimus: Angelos, archangelos, virtutes, potestates, principatus,\ndominationae, thronos, cherubin atque seraphin.\"  Divi Gregorii,\nHom. xxxiv. f. 125.  ed. Par. 1518. fol.\n\nv. 126.  He had learnt.]  Dionysius, he says, had learnt from St.\nPaul. It is almost unnecessary to add, that the book, above\nreferred to, which goes under his name, was the production of a\nlater age.\n\nCANTO XXIX\n\nv. 1.  No longer.]  As short a space, as the sun and moon are in\nchanging hemispheres, when they are opposite to one another, the\none under the sign of Aries, and the other under that of Libra,\nand both hang for a moment, noised as it were in the hand of the\nzenith.\n\nv. 22.  For, not in process of before or aft.]  There was neither\n\"before nor after,\" no distinction, that is, of time, till the\ncreation of the world.\n\nv. 30.  His threefold operation.]  He seems to mean that\nspiritual beings, brute matter, and the intermediate part of the\ncreation, which participates both of spirit and matter, were\nproduced at once.\n\nv. 38.  On Jerome\'s pages.]  St. Jerome had described the angels\nas created before the rest of the universe: an opinion which\nThomas  Aquinas controverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye c");
    strcat(expected_filecontent, "omm");

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "CATCH.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 7511, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[7511] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[7511], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(12356, 1);
            char expected_filecontent[12357] = "";

            strcat(expected_filecontent, " him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefo");
    strcat(expected_filecontent, "re on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards u");
    strcat(expected_filecontent, "s came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer know");
    strcat(expected_filecontent, "n,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit dow");

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "BEHIND.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -3414, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[8942] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[8942], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(12356, 1);
            char expected_filecontent[12357] = "";

            strcat(expected_filecontent, " him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefo");
    strcat(expected_filecontent, "re on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards u");
    strcat(expected_filecontent, "s came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer know");
    strcat(expected_filecontent, "n,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit dow");

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "BEHIND.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 374, SEEK_SET);
            file_seek(file, 2149, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2523] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2523], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "THAN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (THAN) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "FIVE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (FIVE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "DESCRIBE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (DESCRIBE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "PLAIN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (PLAIN) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "STORY");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (STORY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SYSTEM");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SYSTEM) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WEST");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WEST) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SAND.TX");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie SAND.TX, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "SAND.TX");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "AMONG.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[14] = { "AMONG.TX", "PROCESS.BIN", "SEND", "ROW", "CATCH.TX", "BEHIND.BIN", "BROKELAN", "THAN", "FIVE", "DESCRIBE", "PLAIN", "STORY", "SYSTEM", "WEST" };
            int found_names[14] = { 0 };

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 14; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 14; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "AMONG.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "PROCESS.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SEND");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "ROW");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "CATCH.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "BEHIND.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "BROKELAN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("right_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "end");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST30, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST31, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_close
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(53); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}