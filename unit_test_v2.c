/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Mateusz Kapka
 * Test wygenerowano automatycznie o 2023-01-16 20:15:21.854261
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
    


            struct disk_t* disk = disk_open_from_file("WAS.TXT");
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
    


            struct disk_t* disk = disk_open_from_file("back.img");
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
    
        
                char *filecontent = (char *)calloc(425, 1);
                char expected_filecontent[426] = "";
        
                strcat(expected_filecontent, " farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SKY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 425, file);
                test_error(size == 425, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 425 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 425);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 425);


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
    
        
                char *filecontent = (char *)calloc(6556, 1);
                char expected_filecontent[6557] = "";
        
                strcat(expected_filecontent, "rd tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer known,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit down a precipice,\nWhere space enough to lodge a thousand spreads;\nThus downward from a craggy steep we found,\nThat this dark wave resounded, roaring loud,\nSo that the ear its clamour soon had stunn\'d.\n     I had a cord that brac\'d my girdle round,\nWherewith I erst had thought fast bound to take\nThe painted leopard.  This when I had all\nUnloosen\'d from me (so my master bade)\nI gather\'d up, and stretch\'d it forth to him.\nThen to the right he turn\'d, and from the brink\nStanding few paces distant, cast it down\nInto the deep abyss.  \"And somewhat strange,\"\nThus to myself I spake, \"signal so strange\nBetokens, which my guide with earnest eye\nThus follows.\"  Ah! what caution must men use\nWith those who look not at the deed alone,\nBut spy into the thoughts with subtle skill!\n     \"Quickly shall come,\" he said, \"what I expect,\nThine eye discover quickly, that whereof\nThy thought is dreaming.\"  Ever to that truth,\nWhich but the semblance of a falsehood wears,\nA man, if possible, should bar his lip;\nSince, although blameless, he incurs reproach.\nBut silence here were vain; and by these notes\nWhich now I sing, reader!  I swear to thee,\nSo may they favour find to latest times!\nThat through the gross and murky air I spied\nA shape come swimming up, that might have quell\'d\nThe stoutest heart with wonder, in such guise\nAs one returns, who hath been down to loose\nAn anchor grappled fast against some rock,\nOr to aught else that in the salt wave lies,\nWho upward springing close draws in his feet.\n\n\n\nCANTO XVII\n\n\"LO! the fell monster with the deadly sting!\nWho passes mountains, breaks through fenced walls\nAnd firm embattled spears, and with his filth\nTaints all the world!\"  Thus me my guide address\'d,\nAnd beckon\'d him, that he should come to shore,\nNear to the stony causeway\'s utmost edge.\n     Forthwith that image vile of fraud appear\'d,\nHis head and upper part expos\'d on land,\nBut laid not on the shore his bestial train.\nHis face the semblance of a just man\'s wore,\nSo kind and gracious was its outward cheer;\nThe rest was serpent all:  two shaggy claws\nReach\'d to the armpits, and the back and breast,\nAnd either side, were painted o\'er with nodes\nAnd orbits.  Colours variegated more\nNor Turks nor Tartars e\'er on cloth of state\nWith interchangeable embroidery wove,\nNor spread Arachne o\'er her curious loom.\nAs ofttimes a light skiff, moor\'d to the shore,\nStands part in water, part upon the land;\nOr, a");
    strcat(expected_filecontent, "s where dwells the greedy German boor,\nThe beaver settles watching for his prey;\nSo on the rim, that fenc\'d the sand with rock,\nSat perch\'d the fiend of evil.  In the void\nGlancing, his tail upturn\'d its venomous fork,\nWith sting like scorpion\'s arm\'d.  Then thus my guide:\n\"Now need our way must turn few steps apart,\nFar as to that ill beast, who couches there.\"\n     Thereat toward the right our downward course\nWe shap\'d, and, better to escape the flame\nAnd burning marle, ten paces on the verge\nProceeded.  Soon as we to him arrive,\nA little further on mine eye beholds\nA tribe of spirits, seated on the sand\nNear the wide chasm.  Forthwith my master spake:\n\"That to the full thy knowledge may extend\nOf all this round contains, go now, and mark\nThe mien these wear:  but hold not long discourse.\nTill thou returnest, I with him meantime\nWill parley, that to us he may vouchsafe\nThe aid of his strong shoulders.\"  Thus alone\nYet forward on the\' extremity I pac\'d\nOf that seventh circle, where the mournful tribe\nWere seated.  At the eyes forth gush\'d their pangs.\nAgainst the vapours and the torrid soil\nAlternately their shifting hands they plied.\nThus use the dogs in summer still to ply\nTheir jaws and feet by turns, when bitten sore\nBy gnats, or flies, or gadflies swarming round.\n     Noting the visages of some, who lay\nBeneath the pelting of that dolorous fire,\nOne of them all I knew not; but perceiv\'d,\nThat pendent from his neck each bore a pouch\nWith colours and with emblems various mark\'d,\nOn which it seem\'d as if their eye did feed.\n     And when amongst them looking round I came,\nA yellow purse I saw with azure wrought,\nThat wore a lion\'s countenance and port.\nThen still my sight pursuing its career,\nAnother I beheld, than blood more red.\nA goose display of whiter wing than curd.\nAnd one, who bore a fat and azure swine\nPictur\'d on his white scrip, addressed me thus:\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "PAINT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6556, file);
                test_error(size == 6556, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6556 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6556);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6556);


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
    
        
                char *filecontent = (char *)calloc(7928, 1);
                char expected_filecontent[7929] = "";
        
                strcat(expected_filecontent, ", and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light\nOf gladness that is in them, well to scan,\nThose yonder three, of deeper ken than ours,\nThy sight shall quicken.\"  Thus began their song;\nAnd then they led me to the Gryphon\'s breast,\nWhile, turn\'d toward us, Beatrice stood.\n\"Spare not thy vision.  We have stationed thee\nBefore the emeralds, whence love erewhile\nHath drawn his weapons on thee.  \"As they spake,\nA thousand fervent wishes riveted\nMine eyes upon her beaming eyes, that stood\nStill fix\'d toward the Gryphon motionless.\nAs the sun strikes a mirror, even thus\nWithin those orbs the twofold being, shone,\nFor ever varying, in one figure now\nReflected, now in other.  Reader!  muse\nHow wond\'rous in my sight it seem\'d to mark\nA thing, albeit steadfast in itself,\nYet in its imag\'d semblance mutable.\n     Full of amaze, and joyous, while my soul\nFed on the viand, whereof still desire\nGrows with satiety, the other three\nWith gesture, that declar\'d a loftier line,\nAdvanc\'d: to their own carol on they came\nDancing in festive ring angelical.\n     \"Turn, Beatrice!\" was their song:  \"O turn\nThy saintly sight on this thy faithful one,\nWho to behold thee many a wearisome pace\nHath measur\'d.  Gracious at our pray\'r vouchsafe\nUnveil to him thy cheeks: that he may mark\nThy second beauty, now conceal\'d.\"  O splendour!\nO sacred light eternal!  who is he\nSo pale with musing in Pierian shades,\nOr with that fount so lavishly imbued,\nWhose spirit should not fail him in th\' essay\nTo represent thee such as thou didst seem,\nWhen under cope of the still-chiming heaven\nThou gav\'st to open air thy charms reveal\'d.\n\n\n\nCANTO XXXII\n\nMine eyes with such an eager coveting,\nWere bent to rid them of their ten years\' thirst,\nNo other sense was waking: and e\'en they\nWere fenc\'d on either side from heed of aught;\nSo tangled in its custom\'d toils that smile\nOf saintly brightness drew me to itself,\nWhen forcibly toward the left my sight\nThe sacred virgins turn\'d; for from their lips\nI heard the warning sounds:  \"Too fix\'d a gaze!\"\n     Awhile my vision labor\'d; as when late\nUpon the\' o\'erstrained eyes the sun hath smote:\nBut soon to lesser object, as the view\nWas now recover\'d (lesser in respect\nTo that excess of sensible, whence late\n");
    strcat(expected_filecontent, "I had perforce been sunder\'d) on their right\nI mark\'d that glorious army wheel, and turn,\nAgainst the sun and sev\'nfold lights, their front.\nAs when, their bucklers for protection rais\'d,\nA well-rang\'d troop, with portly banners curl\'d,\nWheel circling, ere the whole can change their ground:\nE\'en thus the goodly regiment of heav\'n\nProceeding, all did pass us, ere the car\nHad slop\'d his beam.  Attendant at the wheels\nThe damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we mov\'d, as far\nPerchance as arrow at three several flights\nFull wing\'d had sped, when from her station down\nDescended Beatrice.  With one voice\nAll murmur\'d  \"Adam,\" circling next a plant\nDespoil\'d of flowers and leaf on every bough.\nIts tresses, spreading more as more they rose,\nWere such, as \'midst their forest wilds for height\nThe Indians might have gaz\'d at.  \"Blessed thou!\nGryphon, whose beak hath never pluck\'d that tree\nPleasant to taste: for hence the appetite\nWas warp\'d to evil.\"  Round the stately trunk\nThus shouted forth the rest, to whom return\'d\nThe animal twice-gender\'d:  \"Yea: for so\nThe generation of the just are sav\'d.\"\nAnd turning to the chariot-pole, to foot\nHe drew it of the widow\'d branch, and bound\nThere left unto the stock whereon it grew.\n     As when large floods of radiance from above\nStream, with that radiance mingled, which ascends\nNext after setting of the scaly sign,\nOur plants then burgeon, and each wears anew\nHis wonted colours, ere the sun have yok\'d\nBeneath another star his flamy steeds;\nThus putting forth a hue, more faint than rose,\nAnd deeper than the violet, was renew\'d\nThe plant, erewhile in all its branches bare.\n     Unearthly was the hymn, which then arose.\nI understood it not, nor to the end\nEndur\'d the harmony.  Had I the skill\nTo pencil forth, how clos\'d th\' unpitying eyes\nSlumb\'ring, when Syrinx warbled, (eyes that paid\nSo dearly for their watching,) then like painter,\nThat with a model paints, I might design\nThe manner of my falling into sleep.\nBut feign who will the slumber cunningly;\nI pass it by to when I wak\'d, and tell\nHow suddenly a flash of splendour rent\nThe curtain of my sleep, and one cries out:\n\"Arise, what dost thou?\"  As the chosen three,\nOn Tabor\'s mount, admitted to behold\nThe blossoming of that fair tree, whose fruit\nIs coveted of angels, and doth make\nPerpetual feast in heaven, to themselves\nReturning at the word, whence deeper sleeps\nWere broken, that they their tribe diminish\'d saw,\nBoth Moses and Elias gone, and chang\'d\nThe stole their master wore: thus to myself\nReturning, over me beheld I stand\nThe piteous one, who cross the stream had brought\nMy steps.  \"And where,\" all doubting, I exclaim\'d,\n\"Is Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nT");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SOFT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 7928, file);
                test_error(size == 7928, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7928 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7928);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 7928);


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
    
        
                char *filecontent = (char *)calloc(7816, 1);
                char expected_filecontent[7817] = "";
        
                strcat(expected_filecontent, "eriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose fair height my lady\'s eyes did lift me,\nAnd after through this heav\'n from light to light,\nHave I learnt that, which if I tell again,\nIt may with many woefully disrelish;\nAnd, if I am a timid friend to truth,\nI fear my life may perish among those,\nTo whom these days shall be of ancient date.\"\n     The brightness, where enclos\'d the treasure smil\'d,\nWhich I had found there, first shone glisteningly,\nLike to a golden mirror in the sun;\nNext answer\'d:  \"Conscience, dimm\'d or by its own\nOr other\'s shame, will feel thy saying sharp.\nThou, notwithstanding, all deceit remov\'d,\nSee the whole vision be made manifest.\nAnd let them wince who have their withers wrung.\nWhat though, when tasted first, thy voice shall prove\nUnwelcome, on digestion it will turn\nTo vital nourishment.  The cry thou raisest,\nShall, as the wind doth, smite the proudest summits;\nWhich is of honour no light argument,\nFor this there only have been shown to thee,\nThroughout these orbs, the mountain, and the deep,\nSpirits, whom fame hath note of");
    strcat(expected_filecontent, ".  For the mind\nOf him, who hears, is loth to acquiesce\nAnd fix its faith, unless the instance brought\nBe palpable, and proof apparent urge.\"\n\n\n\nCANTO XVIII\n\nNow in his word, sole, ruminating, joy\'d\nThat blessed spirit; and I fed on mine,\nTempting the sweet with bitter:  she meanwhile,\nWho led me unto God, admonish\'d:  \"Muse\nOn other thoughts: bethink thee, that near Him\nI dwell, who recompenseth every wrong.\"\n     At the sweet sounds of comfort straight I turn\'d;\nAnd, in the saintly eyes what love was seen,\nI leave in silence here:  nor through distrust\nOf my words only, but that to such bliss\nThe mind remounts not without aid.  Thus much\nYet may I speak; that, as I gaz\'d on her,\nAffection found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-f");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "DROP.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 7816, file);
                test_error(size == 7816, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7816 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7816);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 7816);


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
    
        
                char *filecontent = (char *)calloc(5722, 1);
                char expected_filecontent[5723] = "";
        
                strcat(expected_filecontent, "f Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if ");
    strcat(expected_filecontent, "it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rustic");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "WHOLE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5722, file);
                test_error(size == 5722, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5722 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5722);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5722);


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
    
        
                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";
        
                strcat(expected_filecontent, "ceeding,\nAs it hath grave beyond its virtue great.\nOur shape, regarmented with glorious weeds\nOf saintly flesh, must, being thus entire,\nShow yet more gracious.  Therefore shall increase,\nWhate\'er of light, gratuitous, imparts\nThe Supreme Good; light, ministering aid,\nThe better disclose his glory: whence\nThe vision needs increasing, much increase\nThe fervour, which it kindles; and that too\nThe ray, that comes from it.  But as the greed\nWhich gives out flame, yet it its whiteness shines\nMore lively than that, and so preserves\nIts proper semblance; thus this circling sphere\nOf splendour, shall to view less radiant seem,\nThan shall our fleshly robe, which yonder earth\nNow covers.  Nor will such excess of light\nO\'erpower us, in corporeal organs made\nFirm, and susceptible of all delight.\"\n     So ready and so cordial an \"Amen,\"\nFollowed from either choir, as plainly spoke\nDesire of their dead bodies; yet perchance\nNot for themselves, but for their kindred dear,\nMothers and sires, and those whom best they lov\'d,\nEre they were made imperishable flame.\n     And lo!  forthwith there rose up round about\nA lustre over that already there,\nOf equal clearness, like the brightening up\nOf the horizon.  As at an evening hour\nOf twilight, new appearances through heav\'n\nPeer with faint glimmer, doubtfully descried;\nSo there new substances, methought began\nTo rise in view; and round the other twain\nEnwheeling, sweep their ampler circuit wide.\n     O gentle glitter of eternal beam!\nWith what a such whiteness did it flow,\nO\'erpowering vision in me!  But so fair,\nSo passing lovely, Beatrice show\'d,\nMind cannot follow it, nor words express\nHer infinite sweetness.  Thence mine eyes regain\'d\nPower to look up, and I beheld myself,\nSole with my lady, to more lofty bliss\nTranslated:  for the star, with warmer smile\nImpurpled, well denoted our ascent.\n     With all the heart, and with that tongue which speaks\nThe same in all, an holocaust I made\nTo God, befitting the new grace vouchsaf\'d.\nAnd from my bosom had not yet upsteam\'d\nThe fuming of that incense, when I knew\nThe rite accepted.  With such mighty sheen\nAnd mantling crimson, in two listed rays\nThe splendours shot before me, that I cried,\n\"God of Sabaoth!  that does prank them thus!\"\n     As leads the galaxy from pole to pole,\nDistinguish\'d into greater lights and less,\nIts pathway, which the wisest fail to spell;\nSo thickly studded, in the depth of Mars,\nThose rays describ\'d the venerable sign,\nThat quadrants in the round conjoining frame.\nHere memory mocks the toil of genius.  Christ\nBeam\'d on that cross; and pattern fails me now.\nBut whoso takes his cross, and follows Christ\nWill pardon me for that I leave untold,\nWhen in the flecker\'d dawning he shall spy\nThe glitterance of Christ.  From horn to horn,\nAnd \'tween the summit and the base did move\nLights, scintillating, as they met and pass\'d.\nThus oft are seen, with ever-changeful glance,\nStraight or athwart, now rapid and now slow,\nThe atomies of bodies, long or short,\nTo move along the sunbeam, whose slant line\nCheckers the shadow, interpos\'d by art\nAgainst the noontide heat.  And as the chime\nOf minstrel music, dulcimer, and help\nWith many strings, a pleasant dining makes\nTo him, who heareth not distinct the note;\nSo from the lights, which there appear\'d to me,\nGather\'d along the cross a melody,\nThat, indistinctly heard, with ravishment\nPossess\'d me.  Yet I mark\'d it was a hymn\nOf lofty praises; for there came to me\n\"Arise and conquer,\" as to one who hears\nAnd comprehends not.  Me such ecstasy\nO\'ercame, that never till that hour was thing\nThat held me in so sweet imprisonment.\n     Perhaps my saying over bold appears,\nAccounting less the pleasure of those eyes,\nWhereon to look fulfilleth all desire.\nBut he, who is aware those living seals\nOf every beauty work with quicker force,\nThe higher they are ris\'n; and that there\nI had not turn\'d me to them; he may well\nExcuse me that, whereof in my excuse\nI do accuse me, and may own my truth;\nThat holy pleasure here not yet reveal\'d,\nWhich grows in transport as we mount aloof.\n\n\n\nCANTO XV\n\nTrue lo");
    strcat(expected_filecontent, "ve, that ever shows itself as clear\nIn kindness, as loose appetite in wrong,\nSilenced that lyre harmonious, and still\'d\nThe sacred chords, that are by heav\'n\'s right hand\nUnwound and tighten\'d, flow to righteous prayers\nShould they not hearken, who, to give me will\nFor praying, in accordance thus were mute?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the s");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "MAP");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6144, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6144);


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
    
        
                char *filecontent = (char *)calloc(5936, 1);
                char expected_filecontent[5937] = "";
        
                strcat(expected_filecontent, "leety flaw\nThrough the dun midnight air stream\'d down amain:\nStank all the land whereon that tempest fell.\n     Cerberus, cruel monster, fierce and strange,\nThrough his wide threefold throat barks as a dog\nOver the multitude immers\'d beneath.\nHis eyes glare crimson, black his unctuous beard,\nHis belly large, and claw\'d the hands, with which\nHe tears the spirits, flays them, and their limbs\nPiecemeal disparts.  Howling there spread, as curs,\nUnder the rainy deluge, with one side\nThe other screening, oft they roll them round,\nA wretched, godless crew.  When that great worm\nDescried us, savage Cerberus, he op\'d\nHis jaws, and the fangs show\'d us; not a limb\nOf him but trembled.  Then my guide, his palms\nExpanding on the ground, thence filled with earth\nRais\'d them, and cast it in his ravenous maw.\nE\'en as a dog, that yelling bays for food\nHis keeper, when the morsel comes, lets fall\nHis fury, bent alone with eager haste\nTo swallow it; so dropp\'d the loathsome cheeks\nOf demon Cerberus, who thund\'ring stuns\nThe spirits, that they for deafness wish in vain.\n     We, o\'er the shades thrown prostrate by the brunt\nOf the heavy tempest passing, set our feet\nUpon their emptiness, that substance seem\'d.\n     They all along the earth extended lay\nSave one, that sudden rais\'d himself to sit,\nSoon as that way he saw us pass.  \"O thou!\"\nHe cried, \"who through the infernal shades art led,\nOwn, if again thou know\'st me.  Thou wast fram\'d\nOr ere my frame was broken.\"  I replied:\n\"The anguish thou endur\'st perchance so takes\nThy form from my remembrance, that it seems\nAs if I saw thee never.  But inform\nMe who thou art, that in a place so sad\nArt set, and in such torment, that although\nOther be greater, more disgustful none\nCan be imagin\'d.\"  He in answer thus:\n\"Thy city heap\'d with envy to the brim,\nAy that the measure overflows its bounds,\nHeld me in brighter days.  Ye citizens\nWere wont to name me Ciacco.  For the sin\nOf glutt\'ny, damned vice, beneath this rain,\nE\'en as thou see\'st, I with fatigue am worn;\nNor I sole spirit in this woe:  all these\nHave by like crime incurr\'d like punishment.\"\n     No more he said, and I my speech resum\'d:\n\"Ciacco!  thy dire affliction grieves me much,\nEven to tears.  But tell me, if thou know\'st,\nWhat shall at length befall the citizens\nOf the divided city;  whether any just one\nInhabit there:  and tell me of the cause,\nWhence jarring discord hath assail\'d it thus?\"\n     He then: \"After long striving they will come\nTo blood; and the wild party from the woods\nWill chase the other with much injury forth.\nThen it behoves, that this must fall, within\nThree solar circles; and the other rise\nBy borrow\'d force of one, who under shore\nNow rests.  It shall a long space hold aloof\nIts forehead, keeping under heavy weight\nThe other oppress\'d, indignant at the load,\nAnd grieving sore.  The just are two in number,\nBut they neglected.  Av\'rice, envy, pride,\nThree fatal sparks, have set the hearts of all\nOn fire.\"  Here ceas\'d the lamentable sound;\nAnd I continu\'d thus: \"Still would I learn\nMore from thee, farther parley still entreat.\nOf Farinata and Tegghiaio say,\nThey who so well deserv\'d, of Giacopo,\nArrigo, Mosca, and the rest, who bent\nTheir minds on working good.  Oh!  tell me where\nThey bide, and to their knowledge let me come.\nFor I am press\'d with keen desire to hear,\nIf heaven\'s sweet cup or poisonous drug of hell\nBe to their lip assign\'d.\"   He answer\'d straight:\n\"These are yet blacker spirits.  Various crimes\nHave sunk them deeper in the dark abyss.\nIf thou so far descendest, thou mayst see them.\nBut to the pleasant world when thou return\'st,\nOf me make mention, I entreat thee, there.\nNo more I tell thee, answer thee no more.\"\n     This said, his fixed eyes he turn\'d askance,\nA little ey\'d me, then bent down his head,\nAnd \'midst his blind companions with it fell.\n     When thus my guide:  \"No more his bed he leaves,\nEre the last angel-trumpet blow.  The Power\nAdverse to these shall then in glory come,\nEach one forthwith to his sad tomb repair,\nResume his fleshly vesture and his form,\nAnd hear the eternal d");
    strcat(expected_filecontent, "oom re-echoing rend\nThe vault.\"  So pass\'d we through that mixture foul\nOf spirits and rain, with tardy steps; meanwhile\nTouching, though slightly, on the life to come.\nFor thus I question\'d:  \"Shall these tortures, Sir!\nWhen the great sentence passes, be increas\'d,\nOr mitigated, or as now severe?\"\n     He then:  \"Consult thy knowledge; that decides\nThat as each thing to more perfection grows,\nIt feels more sensibly both good and pain.\nThough ne\'er to true perfection may arrive\nThis race accurs\'d, yet nearer then than now\nThey shall approach it.\"  Compassing that path\nCircuitous we journeyed, and discourse\nMuch more than I relate between us pass\'d:\nTill at the point, where the steps led below,\nArriv\'d, there Plutus, the great foe, we found.\n\n\n\nCANTO VII\n\n\"AH me!  O Satan!  Satan!\" loud exclaim\'d\nPlutus, in accent hoarse of wild alarm:\nAnd the kind sage, whom no event surpris\'d,\nTo comfort me thus spake:  \"Let not thy fear\nHarm thee, for power in him, be sure, is none\nTo hinder down this rock thy safe descent.\"\nThen to that sworn lip turning, \" Peace!\"  he cried,\n\"Curs\'d wolf!  thy fury inward on thyself\nPrey, and consume thee!  Through the dark profound\nNot without cause he passes.  So \'t is will\'d\nOn high, there where the great Archangel pour\'d\nHeav\'n\'s vengeance on the first adulterer proud.\"\n     As sails full spread and bellying with the wind\nDrop suddenly collaps\'d, if the mast split;\nSo to the ground down dropp\'d the cruel fiend.\n     Thus we, descending to the fourth steep ledge,\nGain\'d on the dismal shore, that all the woe\nHems in of all the universe.  Ah me!\nAlmighty Justice!  in what store thou heap\'st\nNew pains, new troubles, as I here beheld!\nWherefore doth fault of ours bring us to this?\n     E\'en as a billow, on Charybdis rising,\nAgainst encounter\'d billow dashing breaks;\nSuch is the dance this w");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "YOUNG.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5936, file);
                test_error(size == 5936, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5936 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5936);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5936);


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
    
        
                char *filecontent = (char *)calloc(127, 1);
                char expected_filecontent[128] = "";
        
                strcat(expected_filecontent, "rite, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as sh");
                
        
                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "NEIGHBOR");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 127, file);
                test_error(size == 127, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 127 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 127);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 127);


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
    

                char *filecontent = (char *)calloc(425, 1);
                char expected_filecontent[426] = "";

                strcat(expected_filecontent, " farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SKY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 529, file);
                test_error(size == 425, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 425 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 425);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 425);


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
    

                char *filecontent = (char *)calloc(6556, 1);
                char expected_filecontent[6557] = "";

                strcat(expected_filecontent, "rd tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer known,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit down a precipice,\nWhere space enough to lodge a thousand spreads;\nThus downward from a craggy steep we found,\nThat this dark wave resounded, roaring loud,\nSo that the ear its clamour soon had stunn\'d.\n     I had a cord that brac\'d my girdle round,\nWherewith I erst had thought fast bound to take\nThe painted leopard.  This when I had all\nUnloosen\'d from me (so my master bade)\nI gather\'d up, and stretch\'d it forth to him.\nThen to the right he turn\'d, and from the brink\nStanding few paces distant, cast it down\nInto the deep abyss.  \"And somewhat strange,\"\nThus to myself I spake, \"signal so strange\nBetokens, which my guide with earnest eye\nThus follows.\"  Ah! what caution must men use\nWith those who look not at the deed alone,\nBut spy into the thoughts with subtle skill!\n     \"Quickly shall come,\" he said, \"what I expect,\nThine eye discover quickly, that whereof\nThy thought is dreaming.\"  Ever to that truth,\nWhich but the semblance of a falsehood wears,\nA man, if possible, should bar his lip;\nSince, although blameless, he incurs reproach.\nBut silence here were vain; and by these notes\nWhich now I sing, reader!  I swear to thee,\nSo may they favour find to latest times!\nThat through the gross and murky air I spied\nA shape come swimming up, that might have quell\'d\nThe stoutest heart with wonder, in such guise\nAs one returns, who hath been down to loose\nAn anchor grappled fast against some rock,\nOr to aught else that in the salt wave lies,\nWho upward springing close draws in his feet.\n\n\n\nCANTO XVII\n\n\"LO! the fell monster with the deadly sting!\nWho passes mountains, breaks through fenced walls\nAnd firm embattled spears, and with his filth\nTaints all the world!\"  Thus me my guide address\'d,\nAnd beckon\'d him, that he should come to shore,\nNear to the stony causeway\'s utmost edge.\n     Forthwith that image vile of fraud appear\'d,\nHis head and upper part expos\'d on land,\nBut laid not on the shore his bestial train.\nHis face the semblance of a just man\'s wore,\nSo kind and gracious was its outward cheer;\nThe rest was serpent all:  two shaggy claws\nReach\'d to the armpits, and the back and breast,\nAnd either side, were painted o\'er with nodes\nAnd orbits.  Colours variegated more\nNor Turks nor Tartars e\'er on cloth of state\nWith interchangeable embroidery wove,\nNor spread Arachne o\'er her curious loom.\nAs ofttimes a light skiff, moor\'d to the shore,\nStands part in water, part upon the land;\nOr, a");
    strcat(expected_filecontent, "s where dwells the greedy German boor,\nThe beaver settles watching for his prey;\nSo on the rim, that fenc\'d the sand with rock,\nSat perch\'d the fiend of evil.  In the void\nGlancing, his tail upturn\'d its venomous fork,\nWith sting like scorpion\'s arm\'d.  Then thus my guide:\n\"Now need our way must turn few steps apart,\nFar as to that ill beast, who couches there.\"\n     Thereat toward the right our downward course\nWe shap\'d, and, better to escape the flame\nAnd burning marle, ten paces on the verge\nProceeded.  Soon as we to him arrive,\nA little further on mine eye beholds\nA tribe of spirits, seated on the sand\nNear the wide chasm.  Forthwith my master spake:\n\"That to the full thy knowledge may extend\nOf all this round contains, go now, and mark\nThe mien these wear:  but hold not long discourse.\nTill thou returnest, I with him meantime\nWill parley, that to us he may vouchsafe\nThe aid of his strong shoulders.\"  Thus alone\nYet forward on the\' extremity I pac\'d\nOf that seventh circle, where the mournful tribe\nWere seated.  At the eyes forth gush\'d their pangs.\nAgainst the vapours and the torrid soil\nAlternately their shifting hands they plied.\nThus use the dogs in summer still to ply\nTheir jaws and feet by turns, when bitten sore\nBy gnats, or flies, or gadflies swarming round.\n     Noting the visages of some, who lay\nBeneath the pelting of that dolorous fire,\nOne of them all I knew not; but perceiv\'d,\nThat pendent from his neck each bore a pouch\nWith colours and with emblems various mark\'d,\nOn which it seem\'d as if their eye did feed.\n     And when amongst them looking round I came,\nA yellow purse I saw with azure wrought,\nThat wore a lion\'s countenance and port.\nThen still my sight pursuing its career,\nAnother I beheld, than blood more red.\nA goose display of whiter wing than curd.\nAnd one, who bore a fat and azure swine\nPictur\'d on his white scrip, addressed me thus:\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PAINT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6909, file);
                test_error(size == 6556, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6556 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6556);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6556);


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
    

                char *filecontent = (char *)calloc(7928, 1);
                char expected_filecontent[7929] = "";

                strcat(expected_filecontent, ", and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light\nOf gladness that is in them, well to scan,\nThose yonder three, of deeper ken than ours,\nThy sight shall quicken.\"  Thus began their song;\nAnd then they led me to the Gryphon\'s breast,\nWhile, turn\'d toward us, Beatrice stood.\n\"Spare not thy vision.  We have stationed thee\nBefore the emeralds, whence love erewhile\nHath drawn his weapons on thee.  \"As they spake,\nA thousand fervent wishes riveted\nMine eyes upon her beaming eyes, that stood\nStill fix\'d toward the Gryphon motionless.\nAs the sun strikes a mirror, even thus\nWithin those orbs the twofold being, shone,\nFor ever varying, in one figure now\nReflected, now in other.  Reader!  muse\nHow wond\'rous in my sight it seem\'d to mark\nA thing, albeit steadfast in itself,\nYet in its imag\'d semblance mutable.\n     Full of amaze, and joyous, while my soul\nFed on the viand, whereof still desire\nGrows with satiety, the other three\nWith gesture, that declar\'d a loftier line,\nAdvanc\'d: to their own carol on they came\nDancing in festive ring angelical.\n     \"Turn, Beatrice!\" was their song:  \"O turn\nThy saintly sight on this thy faithful one,\nWho to behold thee many a wearisome pace\nHath measur\'d.  Gracious at our pray\'r vouchsafe\nUnveil to him thy cheeks: that he may mark\nThy second beauty, now conceal\'d.\"  O splendour!\nO sacred light eternal!  who is he\nSo pale with musing in Pierian shades,\nOr with that fount so lavishly imbued,\nWhose spirit should not fail him in th\' essay\nTo represent thee such as thou didst seem,\nWhen under cope of the still-chiming heaven\nThou gav\'st to open air thy charms reveal\'d.\n\n\n\nCANTO XXXII\n\nMine eyes with such an eager coveting,\nWere bent to rid them of their ten years\' thirst,\nNo other sense was waking: and e\'en they\nWere fenc\'d on either side from heed of aught;\nSo tangled in its custom\'d toils that smile\nOf saintly brightness drew me to itself,\nWhen forcibly toward the left my sight\nThe sacred virgins turn\'d; for from their lips\nI heard the warning sounds:  \"Too fix\'d a gaze!\"\n     Awhile my vision labor\'d; as when late\nUpon the\' o\'erstrained eyes the sun hath smote:\nBut soon to lesser object, as the view\nWas now recover\'d (lesser in respect\nTo that excess of sensible, whence late\n");
    strcat(expected_filecontent, "I had perforce been sunder\'d) on their right\nI mark\'d that glorious army wheel, and turn,\nAgainst the sun and sev\'nfold lights, their front.\nAs when, their bucklers for protection rais\'d,\nA well-rang\'d troop, with portly banners curl\'d,\nWheel circling, ere the whole can change their ground:\nE\'en thus the goodly regiment of heav\'n\nProceeding, all did pass us, ere the car\nHad slop\'d his beam.  Attendant at the wheels\nThe damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we mov\'d, as far\nPerchance as arrow at three several flights\nFull wing\'d had sped, when from her station down\nDescended Beatrice.  With one voice\nAll murmur\'d  \"Adam,\" circling next a plant\nDespoil\'d of flowers and leaf on every bough.\nIts tresses, spreading more as more they rose,\nWere such, as \'midst their forest wilds for height\nThe Indians might have gaz\'d at.  \"Blessed thou!\nGryphon, whose beak hath never pluck\'d that tree\nPleasant to taste: for hence the appetite\nWas warp\'d to evil.\"  Round the stately trunk\nThus shouted forth the rest, to whom return\'d\nThe animal twice-gender\'d:  \"Yea: for so\nThe generation of the just are sav\'d.\"\nAnd turning to the chariot-pole, to foot\nHe drew it of the widow\'d branch, and bound\nThere left unto the stock whereon it grew.\n     As when large floods of radiance from above\nStream, with that radiance mingled, which ascends\nNext after setting of the scaly sign,\nOur plants then burgeon, and each wears anew\nHis wonted colours, ere the sun have yok\'d\nBeneath another star his flamy steeds;\nThus putting forth a hue, more faint than rose,\nAnd deeper than the violet, was renew\'d\nThe plant, erewhile in all its branches bare.\n     Unearthly was the hymn, which then arose.\nI understood it not, nor to the end\nEndur\'d the harmony.  Had I the skill\nTo pencil forth, how clos\'d th\' unpitying eyes\nSlumb\'ring, when Syrinx warbled, (eyes that paid\nSo dearly for their watching,) then like painter,\nThat with a model paints, I might design\nThe manner of my falling into sleep.\nBut feign who will the slumber cunningly;\nI pass it by to when I wak\'d, and tell\nHow suddenly a flash of splendour rent\nThe curtain of my sleep, and one cries out:\n\"Arise, what dost thou?\"  As the chosen three,\nOn Tabor\'s mount, admitted to behold\nThe blossoming of that fair tree, whose fruit\nIs coveted of angels, and doth make\nPerpetual feast in heaven, to themselves\nReturning at the word, whence deeper sleeps\nWere broken, that they their tribe diminish\'d saw,\nBoth Moses and Elias gone, and chang\'d\nThe stole their master wore: thus to myself\nReturning, over me beheld I stand\nThe piteous one, who cross the stream had brought\nMy steps.  \"And where,\" all doubting, I exclaim\'d,\n\"Is Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nT");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SOFT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 8054, file);
                test_error(size == 7928, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7928 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7928);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7928);


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
    

                char *filecontent = (char *)calloc(7816, 1);
                char expected_filecontent[7817] = "";

                strcat(expected_filecontent, "eriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose fair height my lady\'s eyes did lift me,\nAnd after through this heav\'n from light to light,\nHave I learnt that, which if I tell again,\nIt may with many woefully disrelish;\nAnd, if I am a timid friend to truth,\nI fear my life may perish among those,\nTo whom these days shall be of ancient date.\"\n     The brightness, where enclos\'d the treasure smil\'d,\nWhich I had found there, first shone glisteningly,\nLike to a golden mirror in the sun;\nNext answer\'d:  \"Conscience, dimm\'d or by its own\nOr other\'s shame, will feel thy saying sharp.\nThou, notwithstanding, all deceit remov\'d,\nSee the whole vision be made manifest.\nAnd let them wince who have their withers wrung.\nWhat though, when tasted first, thy voice shall prove\nUnwelcome, on digestion it will turn\nTo vital nourishment.  The cry thou raisest,\nShall, as the wind doth, smite the proudest summits;\nWhich is of honour no light argument,\nFor this there only have been shown to thee,\nThroughout these orbs, the mountain, and the deep,\nSpirits, whom fame hath note of");
    strcat(expected_filecontent, ".  For the mind\nOf him, who hears, is loth to acquiesce\nAnd fix its faith, unless the instance brought\nBe palpable, and proof apparent urge.\"\n\n\n\nCANTO XVIII\n\nNow in his word, sole, ruminating, joy\'d\nThat blessed spirit; and I fed on mine,\nTempting the sweet with bitter:  she meanwhile,\nWho led me unto God, admonish\'d:  \"Muse\nOn other thoughts: bethink thee, that near Him\nI dwell, who recompenseth every wrong.\"\n     At the sweet sounds of comfort straight I turn\'d;\nAnd, in the saintly eyes what love was seen,\nI leave in silence here:  nor through distrust\nOf my words only, but that to such bliss\nThe mind remounts not without aid.  Thus much\nYet may I speak; that, as I gaz\'d on her,\nAffection found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-f");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DROP.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 8050, file);
                test_error(size == 7816, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7816 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7816);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7816);


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
    

                char *filecontent = (char *)calloc(5722, 1);
                char expected_filecontent[5723] = "";

                strcat(expected_filecontent, "f Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if ");
    strcat(expected_filecontent, "it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rustic");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WHOLE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6205, file);
                test_error(size == 5722, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5722 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5722);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5722);


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
    

                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "ceeding,\nAs it hath grave beyond its virtue great.\nOur shape, regarmented with glorious weeds\nOf saintly flesh, must, being thus entire,\nShow yet more gracious.  Therefore shall increase,\nWhate\'er of light, gratuitous, imparts\nThe Supreme Good; light, ministering aid,\nThe better disclose his glory: whence\nThe vision needs increasing, much increase\nThe fervour, which it kindles; and that too\nThe ray, that comes from it.  But as the greed\nWhich gives out flame, yet it its whiteness shines\nMore lively than that, and so preserves\nIts proper semblance; thus this circling sphere\nOf splendour, shall to view less radiant seem,\nThan shall our fleshly robe, which yonder earth\nNow covers.  Nor will such excess of light\nO\'erpower us, in corporeal organs made\nFirm, and susceptible of all delight.\"\n     So ready and so cordial an \"Amen,\"\nFollowed from either choir, as plainly spoke\nDesire of their dead bodies; yet perchance\nNot for themselves, but for their kindred dear,\nMothers and sires, and those whom best they lov\'d,\nEre they were made imperishable flame.\n     And lo!  forthwith there rose up round about\nA lustre over that already there,\nOf equal clearness, like the brightening up\nOf the horizon.  As at an evening hour\nOf twilight, new appearances through heav\'n\nPeer with faint glimmer, doubtfully descried;\nSo there new substances, methought began\nTo rise in view; and round the other twain\nEnwheeling, sweep their ampler circuit wide.\n     O gentle glitter of eternal beam!\nWith what a such whiteness did it flow,\nO\'erpowering vision in me!  But so fair,\nSo passing lovely, Beatrice show\'d,\nMind cannot follow it, nor words express\nHer infinite sweetness.  Thence mine eyes regain\'d\nPower to look up, and I beheld myself,\nSole with my lady, to more lofty bliss\nTranslated:  for the star, with warmer smile\nImpurpled, well denoted our ascent.\n     With all the heart, and with that tongue which speaks\nThe same in all, an holocaust I made\nTo God, befitting the new grace vouchsaf\'d.\nAnd from my bosom had not yet upsteam\'d\nThe fuming of that incense, when I knew\nThe rite accepted.  With such mighty sheen\nAnd mantling crimson, in two listed rays\nThe splendours shot before me, that I cried,\n\"God of Sabaoth!  that does prank them thus!\"\n     As leads the galaxy from pole to pole,\nDistinguish\'d into greater lights and less,\nIts pathway, which the wisest fail to spell;\nSo thickly studded, in the depth of Mars,\nThose rays describ\'d the venerable sign,\nThat quadrants in the round conjoining frame.\nHere memory mocks the toil of genius.  Christ\nBeam\'d on that cross; and pattern fails me now.\nBut whoso takes his cross, and follows Christ\nWill pardon me for that I leave untold,\nWhen in the flecker\'d dawning he shall spy\nThe glitterance of Christ.  From horn to horn,\nAnd \'tween the summit and the base did move\nLights, scintillating, as they met and pass\'d.\nThus oft are seen, with ever-changeful glance,\nStraight or athwart, now rapid and now slow,\nThe atomies of bodies, long or short,\nTo move along the sunbeam, whose slant line\nCheckers the shadow, interpos\'d by art\nAgainst the noontide heat.  And as the chime\nOf minstrel music, dulcimer, and help\nWith many strings, a pleasant dining makes\nTo him, who heareth not distinct the note;\nSo from the lights, which there appear\'d to me,\nGather\'d along the cross a melody,\nThat, indistinctly heard, with ravishment\nPossess\'d me.  Yet I mark\'d it was a hymn\nOf lofty praises; for there came to me\n\"Arise and conquer,\" as to one who hears\nAnd comprehends not.  Me such ecstasy\nO\'ercame, that never till that hour was thing\nThat held me in so sweet imprisonment.\n     Perhaps my saying over bold appears,\nAccounting less the pleasure of those eyes,\nWhereon to look fulfilleth all desire.\nBut he, who is aware those living seals\nOf every beauty work with quicker force,\nThe higher they are ris\'n; and that there\nI had not turn\'d me to them; he may well\nExcuse me that, whereof in my excuse\nI do accuse me, and may own my truth;\nThat holy pleasure here not yet reveal\'d,\nWhich grows in transport as we mount aloof.\n\n\n\nCANTO XV\n\nTrue lo");
    strcat(expected_filecontent, "ve, that ever shows itself as clear\nIn kindness, as loose appetite in wrong,\nSilenced that lyre harmonious, and still\'d\nThe sacred chords, that are by heav\'n\'s right hand\nUnwound and tighten\'d, flow to righteous prayers\nShould they not hearken, who, to give me will\nFor praying, in accordance thus were mute?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the s");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MAP");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6367, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6144);


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
    

                char *filecontent = (char *)calloc(5936, 1);
                char expected_filecontent[5937] = "";

                strcat(expected_filecontent, "leety flaw\nThrough the dun midnight air stream\'d down amain:\nStank all the land whereon that tempest fell.\n     Cerberus, cruel monster, fierce and strange,\nThrough his wide threefold throat barks as a dog\nOver the multitude immers\'d beneath.\nHis eyes glare crimson, black his unctuous beard,\nHis belly large, and claw\'d the hands, with which\nHe tears the spirits, flays them, and their limbs\nPiecemeal disparts.  Howling there spread, as curs,\nUnder the rainy deluge, with one side\nThe other screening, oft they roll them round,\nA wretched, godless crew.  When that great worm\nDescried us, savage Cerberus, he op\'d\nHis jaws, and the fangs show\'d us; not a limb\nOf him but trembled.  Then my guide, his palms\nExpanding on the ground, thence filled with earth\nRais\'d them, and cast it in his ravenous maw.\nE\'en as a dog, that yelling bays for food\nHis keeper, when the morsel comes, lets fall\nHis fury, bent alone with eager haste\nTo swallow it; so dropp\'d the loathsome cheeks\nOf demon Cerberus, who thund\'ring stuns\nThe spirits, that they for deafness wish in vain.\n     We, o\'er the shades thrown prostrate by the brunt\nOf the heavy tempest passing, set our feet\nUpon their emptiness, that substance seem\'d.\n     They all along the earth extended lay\nSave one, that sudden rais\'d himself to sit,\nSoon as that way he saw us pass.  \"O thou!\"\nHe cried, \"who through the infernal shades art led,\nOwn, if again thou know\'st me.  Thou wast fram\'d\nOr ere my frame was broken.\"  I replied:\n\"The anguish thou endur\'st perchance so takes\nThy form from my remembrance, that it seems\nAs if I saw thee never.  But inform\nMe who thou art, that in a place so sad\nArt set, and in such torment, that although\nOther be greater, more disgustful none\nCan be imagin\'d.\"  He in answer thus:\n\"Thy city heap\'d with envy to the brim,\nAy that the measure overflows its bounds,\nHeld me in brighter days.  Ye citizens\nWere wont to name me Ciacco.  For the sin\nOf glutt\'ny, damned vice, beneath this rain,\nE\'en as thou see\'st, I with fatigue am worn;\nNor I sole spirit in this woe:  all these\nHave by like crime incurr\'d like punishment.\"\n     No more he said, and I my speech resum\'d:\n\"Ciacco!  thy dire affliction grieves me much,\nEven to tears.  But tell me, if thou know\'st,\nWhat shall at length befall the citizens\nOf the divided city;  whether any just one\nInhabit there:  and tell me of the cause,\nWhence jarring discord hath assail\'d it thus?\"\n     He then: \"After long striving they will come\nTo blood; and the wild party from the woods\nWill chase the other with much injury forth.\nThen it behoves, that this must fall, within\nThree solar circles; and the other rise\nBy borrow\'d force of one, who under shore\nNow rests.  It shall a long space hold aloof\nIts forehead, keeping under heavy weight\nThe other oppress\'d, indignant at the load,\nAnd grieving sore.  The just are two in number,\nBut they neglected.  Av\'rice, envy, pride,\nThree fatal sparks, have set the hearts of all\nOn fire.\"  Here ceas\'d the lamentable sound;\nAnd I continu\'d thus: \"Still would I learn\nMore from thee, farther parley still entreat.\nOf Farinata and Tegghiaio say,\nThey who so well deserv\'d, of Giacopo,\nArrigo, Mosca, and the rest, who bent\nTheir minds on working good.  Oh!  tell me where\nThey bide, and to their knowledge let me come.\nFor I am press\'d with keen desire to hear,\nIf heaven\'s sweet cup or poisonous drug of hell\nBe to their lip assign\'d.\"   He answer\'d straight:\n\"These are yet blacker spirits.  Various crimes\nHave sunk them deeper in the dark abyss.\nIf thou so far descendest, thou mayst see them.\nBut to the pleasant world when thou return\'st,\nOf me make mention, I entreat thee, there.\nNo more I tell thee, answer thee no more.\"\n     This said, his fixed eyes he turn\'d askance,\nA little ey\'d me, then bent down his head,\nAnd \'midst his blind companions with it fell.\n     When thus my guide:  \"No more his bed he leaves,\nEre the last angel-trumpet blow.  The Power\nAdverse to these shall then in glory come,\nEach one forthwith to his sad tomb repair,\nResume his fleshly vesture and his form,\nAnd hear the eternal d");
    strcat(expected_filecontent, "oom re-echoing rend\nThe vault.\"  So pass\'d we through that mixture foul\nOf spirits and rain, with tardy steps; meanwhile\nTouching, though slightly, on the life to come.\nFor thus I question\'d:  \"Shall these tortures, Sir!\nWhen the great sentence passes, be increas\'d,\nOr mitigated, or as now severe?\"\n     He then:  \"Consult thy knowledge; that decides\nThat as each thing to more perfection grows,\nIt feels more sensibly both good and pain.\nThough ne\'er to true perfection may arrive\nThis race accurs\'d, yet nearer then than now\nThey shall approach it.\"  Compassing that path\nCircuitous we journeyed, and discourse\nMuch more than I relate between us pass\'d:\nTill at the point, where the steps led below,\nArriv\'d, there Plutus, the great foe, we found.\n\n\n\nCANTO VII\n\n\"AH me!  O Satan!  Satan!\" loud exclaim\'d\nPlutus, in accent hoarse of wild alarm:\nAnd the kind sage, whom no event surpris\'d,\nTo comfort me thus spake:  \"Let not thy fear\nHarm thee, for power in him, be sure, is none\nTo hinder down this rock thy safe descent.\"\nThen to that sworn lip turning, \" Peace!\"  he cried,\n\"Curs\'d wolf!  thy fury inward on thyself\nPrey, and consume thee!  Through the dark profound\nNot without cause he passes.  So \'t is will\'d\nOn high, there where the great Archangel pour\'d\nHeav\'n\'s vengeance on the first adulterer proud.\"\n     As sails full spread and bellying with the wind\nDrop suddenly collaps\'d, if the mast split;\nSo to the ground down dropp\'d the cruel fiend.\n     Thus we, descending to the fourth steep ledge,\nGain\'d on the dismal shore, that all the woe\nHems in of all the universe.  Ah me!\nAlmighty Justice!  in what store thou heap\'st\nNew pains, new troubles, as I here beheld!\nWherefore doth fault of ours bring us to this?\n     E\'en as a billow, on Charybdis rising,\nAgainst encounter\'d billow dashing breaks;\nSuch is the dance this w");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "YOUNG.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6290, file);
                test_error(size == 5936, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5936 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5936);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5936);


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
    

                char *filecontent = (char *)calloc(127, 1);
                char expected_filecontent[128] = "";

                strcat(expected_filecontent, "rite, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as sh");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "NEIGHBOR");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 571, file);
                test_error(size == 127, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 127 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 127);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 127);


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
    

                char expected_filecontent[426] = "";

                strcat(expected_filecontent, " farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SKY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 425; ++i)
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
    

                char expected_filecontent[6557] = "";

                strcat(expected_filecontent, "rd tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer known,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit down a precipice,\nWhere space enough to lodge a thousand spreads;\nThus downward from a craggy steep we found,\nThat this dark wave resounded, roaring loud,\nSo that the ear its clamour soon had stunn\'d.\n     I had a cord that brac\'d my girdle round,\nWherewith I erst had thought fast bound to take\nThe painted leopard.  This when I had all\nUnloosen\'d from me (so my master bade)\nI gather\'d up, and stretch\'d it forth to him.\nThen to the right he turn\'d, and from the brink\nStanding few paces distant, cast it down\nInto the deep abyss.  \"And somewhat strange,\"\nThus to myself I spake, \"signal so strange\nBetokens, which my guide with earnest eye\nThus follows.\"  Ah! what caution must men use\nWith those who look not at the deed alone,\nBut spy into the thoughts with subtle skill!\n     \"Quickly shall come,\" he said, \"what I expect,\nThine eye discover quickly, that whereof\nThy thought is dreaming.\"  Ever to that truth,\nWhich but the semblance of a falsehood wears,\nA man, if possible, should bar his lip;\nSince, although blameless, he incurs reproach.\nBut silence here were vain; and by these notes\nWhich now I sing, reader!  I swear to thee,\nSo may they favour find to latest times!\nThat through the gross and murky air I spied\nA shape come swimming up, that might have quell\'d\nThe stoutest heart with wonder, in such guise\nAs one returns, who hath been down to loose\nAn anchor grappled fast against some rock,\nOr to aught else that in the salt wave lies,\nWho upward springing close draws in his feet.\n\n\n\nCANTO XVII\n\n\"LO! the fell monster with the deadly sting!\nWho passes mountains, breaks through fenced walls\nAnd firm embattled spears, and with his filth\nTaints all the world!\"  Thus me my guide address\'d,\nAnd beckon\'d him, that he should come to shore,\nNear to the stony causeway\'s utmost edge.\n     Forthwith that image vile of fraud appear\'d,\nHis head and upper part expos\'d on land,\nBut laid not on the shore his bestial train.\nHis face the semblance of a just man\'s wore,\nSo kind and gracious was its outward cheer;\nThe rest was serpent all:  two shaggy claws\nReach\'d to the armpits, and the back and breast,\nAnd either side, were painted o\'er with nodes\nAnd orbits.  Colours variegated more\nNor Turks nor Tartars e\'er on cloth of state\nWith interchangeable embroidery wove,\nNor spread Arachne o\'er her curious loom.\nAs ofttimes a light skiff, moor\'d to the shore,\nStands part in water, part upon the land;\nOr, a");
    strcat(expected_filecontent, "s where dwells the greedy German boor,\nThe beaver settles watching for his prey;\nSo on the rim, that fenc\'d the sand with rock,\nSat perch\'d the fiend of evil.  In the void\nGlancing, his tail upturn\'d its venomous fork,\nWith sting like scorpion\'s arm\'d.  Then thus my guide:\n\"Now need our way must turn few steps apart,\nFar as to that ill beast, who couches there.\"\n     Thereat toward the right our downward course\nWe shap\'d, and, better to escape the flame\nAnd burning marle, ten paces on the verge\nProceeded.  Soon as we to him arrive,\nA little further on mine eye beholds\nA tribe of spirits, seated on the sand\nNear the wide chasm.  Forthwith my master spake:\n\"That to the full thy knowledge may extend\nOf all this round contains, go now, and mark\nThe mien these wear:  but hold not long discourse.\nTill thou returnest, I with him meantime\nWill parley, that to us he may vouchsafe\nThe aid of his strong shoulders.\"  Thus alone\nYet forward on the\' extremity I pac\'d\nOf that seventh circle, where the mournful tribe\nWere seated.  At the eyes forth gush\'d their pangs.\nAgainst the vapours and the torrid soil\nAlternately their shifting hands they plied.\nThus use the dogs in summer still to ply\nTheir jaws and feet by turns, when bitten sore\nBy gnats, or flies, or gadflies swarming round.\n     Noting the visages of some, who lay\nBeneath the pelting of that dolorous fire,\nOne of them all I knew not; but perceiv\'d,\nThat pendent from his neck each bore a pouch\nWith colours and with emblems various mark\'d,\nOn which it seem\'d as if their eye did feed.\n     And when amongst them looking round I came,\nA yellow purse I saw with azure wrought,\nThat wore a lion\'s countenance and port.\nThen still my sight pursuing its career,\nAnother I beheld, than blood more red.\nA goose display of whiter wing than curd.\nAnd one, who bore a fat and azure swine\nPictur\'d on his white scrip, addressed me thus:\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PAINT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6556; ++i)
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
    

                char expected_filecontent[7929] = "";

                strcat(expected_filecontent, ", and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light\nOf gladness that is in them, well to scan,\nThose yonder three, of deeper ken than ours,\nThy sight shall quicken.\"  Thus began their song;\nAnd then they led me to the Gryphon\'s breast,\nWhile, turn\'d toward us, Beatrice stood.\n\"Spare not thy vision.  We have stationed thee\nBefore the emeralds, whence love erewhile\nHath drawn his weapons on thee.  \"As they spake,\nA thousand fervent wishes riveted\nMine eyes upon her beaming eyes, that stood\nStill fix\'d toward the Gryphon motionless.\nAs the sun strikes a mirror, even thus\nWithin those orbs the twofold being, shone,\nFor ever varying, in one figure now\nReflected, now in other.  Reader!  muse\nHow wond\'rous in my sight it seem\'d to mark\nA thing, albeit steadfast in itself,\nYet in its imag\'d semblance mutable.\n     Full of amaze, and joyous, while my soul\nFed on the viand, whereof still desire\nGrows with satiety, the other three\nWith gesture, that declar\'d a loftier line,\nAdvanc\'d: to their own carol on they came\nDancing in festive ring angelical.\n     \"Turn, Beatrice!\" was their song:  \"O turn\nThy saintly sight on this thy faithful one,\nWho to behold thee many a wearisome pace\nHath measur\'d.  Gracious at our pray\'r vouchsafe\nUnveil to him thy cheeks: that he may mark\nThy second beauty, now conceal\'d.\"  O splendour!\nO sacred light eternal!  who is he\nSo pale with musing in Pierian shades,\nOr with that fount so lavishly imbued,\nWhose spirit should not fail him in th\' essay\nTo represent thee such as thou didst seem,\nWhen under cope of the still-chiming heaven\nThou gav\'st to open air thy charms reveal\'d.\n\n\n\nCANTO XXXII\n\nMine eyes with such an eager coveting,\nWere bent to rid them of their ten years\' thirst,\nNo other sense was waking: and e\'en they\nWere fenc\'d on either side from heed of aught;\nSo tangled in its custom\'d toils that smile\nOf saintly brightness drew me to itself,\nWhen forcibly toward the left my sight\nThe sacred virgins turn\'d; for from their lips\nI heard the warning sounds:  \"Too fix\'d a gaze!\"\n     Awhile my vision labor\'d; as when late\nUpon the\' o\'erstrained eyes the sun hath smote:\nBut soon to lesser object, as the view\nWas now recover\'d (lesser in respect\nTo that excess of sensible, whence late\n");
    strcat(expected_filecontent, "I had perforce been sunder\'d) on their right\nI mark\'d that glorious army wheel, and turn,\nAgainst the sun and sev\'nfold lights, their front.\nAs when, their bucklers for protection rais\'d,\nA well-rang\'d troop, with portly banners curl\'d,\nWheel circling, ere the whole can change their ground:\nE\'en thus the goodly regiment of heav\'n\nProceeding, all did pass us, ere the car\nHad slop\'d his beam.  Attendant at the wheels\nThe damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we mov\'d, as far\nPerchance as arrow at three several flights\nFull wing\'d had sped, when from her station down\nDescended Beatrice.  With one voice\nAll murmur\'d  \"Adam,\" circling next a plant\nDespoil\'d of flowers and leaf on every bough.\nIts tresses, spreading more as more they rose,\nWere such, as \'midst their forest wilds for height\nThe Indians might have gaz\'d at.  \"Blessed thou!\nGryphon, whose beak hath never pluck\'d that tree\nPleasant to taste: for hence the appetite\nWas warp\'d to evil.\"  Round the stately trunk\nThus shouted forth the rest, to whom return\'d\nThe animal twice-gender\'d:  \"Yea: for so\nThe generation of the just are sav\'d.\"\nAnd turning to the chariot-pole, to foot\nHe drew it of the widow\'d branch, and bound\nThere left unto the stock whereon it grew.\n     As when large floods of radiance from above\nStream, with that radiance mingled, which ascends\nNext after setting of the scaly sign,\nOur plants then burgeon, and each wears anew\nHis wonted colours, ere the sun have yok\'d\nBeneath another star his flamy steeds;\nThus putting forth a hue, more faint than rose,\nAnd deeper than the violet, was renew\'d\nThe plant, erewhile in all its branches bare.\n     Unearthly was the hymn, which then arose.\nI understood it not, nor to the end\nEndur\'d the harmony.  Had I the skill\nTo pencil forth, how clos\'d th\' unpitying eyes\nSlumb\'ring, when Syrinx warbled, (eyes that paid\nSo dearly for their watching,) then like painter,\nThat with a model paints, I might design\nThe manner of my falling into sleep.\nBut feign who will the slumber cunningly;\nI pass it by to when I wak\'d, and tell\nHow suddenly a flash of splendour rent\nThe curtain of my sleep, and one cries out:\n\"Arise, what dost thou?\"  As the chosen three,\nOn Tabor\'s mount, admitted to behold\nThe blossoming of that fair tree, whose fruit\nIs coveted of angels, and doth make\nPerpetual feast in heaven, to themselves\nReturning at the word, whence deeper sleeps\nWere broken, that they their tribe diminish\'d saw,\nBoth Moses and Elias gone, and chang\'d\nThe stole their master wore: thus to myself\nReturning, over me beheld I stand\nThe piteous one, who cross the stream had brought\nMy steps.  \"And where,\" all doubting, I exclaim\'d,\n\"Is Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nT");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SOFT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7928; ++i)
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
    

                char expected_filecontent[7817] = "";

                strcat(expected_filecontent, "eriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose fair height my lady\'s eyes did lift me,\nAnd after through this heav\'n from light to light,\nHave I learnt that, which if I tell again,\nIt may with many woefully disrelish;\nAnd, if I am a timid friend to truth,\nI fear my life may perish among those,\nTo whom these days shall be of ancient date.\"\n     The brightness, where enclos\'d the treasure smil\'d,\nWhich I had found there, first shone glisteningly,\nLike to a golden mirror in the sun;\nNext answer\'d:  \"Conscience, dimm\'d or by its own\nOr other\'s shame, will feel thy saying sharp.\nThou, notwithstanding, all deceit remov\'d,\nSee the whole vision be made manifest.\nAnd let them wince who have their withers wrung.\nWhat though, when tasted first, thy voice shall prove\nUnwelcome, on digestion it will turn\nTo vital nourishment.  The cry thou raisest,\nShall, as the wind doth, smite the proudest summits;\nWhich is of honour no light argument,\nFor this there only have been shown to thee,\nThroughout these orbs, the mountain, and the deep,\nSpirits, whom fame hath note of");
    strcat(expected_filecontent, ".  For the mind\nOf him, who hears, is loth to acquiesce\nAnd fix its faith, unless the instance brought\nBe palpable, and proof apparent urge.\"\n\n\n\nCANTO XVIII\n\nNow in his word, sole, ruminating, joy\'d\nThat blessed spirit; and I fed on mine,\nTempting the sweet with bitter:  she meanwhile,\nWho led me unto God, admonish\'d:  \"Muse\nOn other thoughts: bethink thee, that near Him\nI dwell, who recompenseth every wrong.\"\n     At the sweet sounds of comfort straight I turn\'d;\nAnd, in the saintly eyes what love was seen,\nI leave in silence here:  nor through distrust\nOf my words only, but that to such bliss\nThe mind remounts not without aid.  Thus much\nYet may I speak; that, as I gaz\'d on her,\nAffection found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-f");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DROP.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7816; ++i)
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
    

                char expected_filecontent[5723] = "";

                strcat(expected_filecontent, "f Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if ");
    strcat(expected_filecontent, "it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rustic");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WHOLE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5722; ++i)
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
    

                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "ceeding,\nAs it hath grave beyond its virtue great.\nOur shape, regarmented with glorious weeds\nOf saintly flesh, must, being thus entire,\nShow yet more gracious.  Therefore shall increase,\nWhate\'er of light, gratuitous, imparts\nThe Supreme Good; light, ministering aid,\nThe better disclose his glory: whence\nThe vision needs increasing, much increase\nThe fervour, which it kindles; and that too\nThe ray, that comes from it.  But as the greed\nWhich gives out flame, yet it its whiteness shines\nMore lively than that, and so preserves\nIts proper semblance; thus this circling sphere\nOf splendour, shall to view less radiant seem,\nThan shall our fleshly robe, which yonder earth\nNow covers.  Nor will such excess of light\nO\'erpower us, in corporeal organs made\nFirm, and susceptible of all delight.\"\n     So ready and so cordial an \"Amen,\"\nFollowed from either choir, as plainly spoke\nDesire of their dead bodies; yet perchance\nNot for themselves, but for their kindred dear,\nMothers and sires, and those whom best they lov\'d,\nEre they were made imperishable flame.\n     And lo!  forthwith there rose up round about\nA lustre over that already there,\nOf equal clearness, like the brightening up\nOf the horizon.  As at an evening hour\nOf twilight, new appearances through heav\'n\nPeer with faint glimmer, doubtfully descried;\nSo there new substances, methought began\nTo rise in view; and round the other twain\nEnwheeling, sweep their ampler circuit wide.\n     O gentle glitter of eternal beam!\nWith what a such whiteness did it flow,\nO\'erpowering vision in me!  But so fair,\nSo passing lovely, Beatrice show\'d,\nMind cannot follow it, nor words express\nHer infinite sweetness.  Thence mine eyes regain\'d\nPower to look up, and I beheld myself,\nSole with my lady, to more lofty bliss\nTranslated:  for the star, with warmer smile\nImpurpled, well denoted our ascent.\n     With all the heart, and with that tongue which speaks\nThe same in all, an holocaust I made\nTo God, befitting the new grace vouchsaf\'d.\nAnd from my bosom had not yet upsteam\'d\nThe fuming of that incense, when I knew\nThe rite accepted.  With such mighty sheen\nAnd mantling crimson, in two listed rays\nThe splendours shot before me, that I cried,\n\"God of Sabaoth!  that does prank them thus!\"\n     As leads the galaxy from pole to pole,\nDistinguish\'d into greater lights and less,\nIts pathway, which the wisest fail to spell;\nSo thickly studded, in the depth of Mars,\nThose rays describ\'d the venerable sign,\nThat quadrants in the round conjoining frame.\nHere memory mocks the toil of genius.  Christ\nBeam\'d on that cross; and pattern fails me now.\nBut whoso takes his cross, and follows Christ\nWill pardon me for that I leave untold,\nWhen in the flecker\'d dawning he shall spy\nThe glitterance of Christ.  From horn to horn,\nAnd \'tween the summit and the base did move\nLights, scintillating, as they met and pass\'d.\nThus oft are seen, with ever-changeful glance,\nStraight or athwart, now rapid and now slow,\nThe atomies of bodies, long or short,\nTo move along the sunbeam, whose slant line\nCheckers the shadow, interpos\'d by art\nAgainst the noontide heat.  And as the chime\nOf minstrel music, dulcimer, and help\nWith many strings, a pleasant dining makes\nTo him, who heareth not distinct the note;\nSo from the lights, which there appear\'d to me,\nGather\'d along the cross a melody,\nThat, indistinctly heard, with ravishment\nPossess\'d me.  Yet I mark\'d it was a hymn\nOf lofty praises; for there came to me\n\"Arise and conquer,\" as to one who hears\nAnd comprehends not.  Me such ecstasy\nO\'ercame, that never till that hour was thing\nThat held me in so sweet imprisonment.\n     Perhaps my saying over bold appears,\nAccounting less the pleasure of those eyes,\nWhereon to look fulfilleth all desire.\nBut he, who is aware those living seals\nOf every beauty work with quicker force,\nThe higher they are ris\'n; and that there\nI had not turn\'d me to them; he may well\nExcuse me that, whereof in my excuse\nI do accuse me, and may own my truth;\nThat holy pleasure here not yet reveal\'d,\nWhich grows in transport as we mount aloof.\n\n\n\nCANTO XV\n\nTrue lo");
    strcat(expected_filecontent, "ve, that ever shows itself as clear\nIn kindness, as loose appetite in wrong,\nSilenced that lyre harmonious, and still\'d\nThe sacred chords, that are by heav\'n\'s right hand\nUnwound and tighten\'d, flow to righteous prayers\nShould they not hearken, who, to give me will\nFor praying, in accordance thus were mute?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the s");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MAP");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6144; ++i)
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
    

                char expected_filecontent[5937] = "";

                strcat(expected_filecontent, "leety flaw\nThrough the dun midnight air stream\'d down amain:\nStank all the land whereon that tempest fell.\n     Cerberus, cruel monster, fierce and strange,\nThrough his wide threefold throat barks as a dog\nOver the multitude immers\'d beneath.\nHis eyes glare crimson, black his unctuous beard,\nHis belly large, and claw\'d the hands, with which\nHe tears the spirits, flays them, and their limbs\nPiecemeal disparts.  Howling there spread, as curs,\nUnder the rainy deluge, with one side\nThe other screening, oft they roll them round,\nA wretched, godless crew.  When that great worm\nDescried us, savage Cerberus, he op\'d\nHis jaws, and the fangs show\'d us; not a limb\nOf him but trembled.  Then my guide, his palms\nExpanding on the ground, thence filled with earth\nRais\'d them, and cast it in his ravenous maw.\nE\'en as a dog, that yelling bays for food\nHis keeper, when the morsel comes, lets fall\nHis fury, bent alone with eager haste\nTo swallow it; so dropp\'d the loathsome cheeks\nOf demon Cerberus, who thund\'ring stuns\nThe spirits, that they for deafness wish in vain.\n     We, o\'er the shades thrown prostrate by the brunt\nOf the heavy tempest passing, set our feet\nUpon their emptiness, that substance seem\'d.\n     They all along the earth extended lay\nSave one, that sudden rais\'d himself to sit,\nSoon as that way he saw us pass.  \"O thou!\"\nHe cried, \"who through the infernal shades art led,\nOwn, if again thou know\'st me.  Thou wast fram\'d\nOr ere my frame was broken.\"  I replied:\n\"The anguish thou endur\'st perchance so takes\nThy form from my remembrance, that it seems\nAs if I saw thee never.  But inform\nMe who thou art, that in a place so sad\nArt set, and in such torment, that although\nOther be greater, more disgustful none\nCan be imagin\'d.\"  He in answer thus:\n\"Thy city heap\'d with envy to the brim,\nAy that the measure overflows its bounds,\nHeld me in brighter days.  Ye citizens\nWere wont to name me Ciacco.  For the sin\nOf glutt\'ny, damned vice, beneath this rain,\nE\'en as thou see\'st, I with fatigue am worn;\nNor I sole spirit in this woe:  all these\nHave by like crime incurr\'d like punishment.\"\n     No more he said, and I my speech resum\'d:\n\"Ciacco!  thy dire affliction grieves me much,\nEven to tears.  But tell me, if thou know\'st,\nWhat shall at length befall the citizens\nOf the divided city;  whether any just one\nInhabit there:  and tell me of the cause,\nWhence jarring discord hath assail\'d it thus?\"\n     He then: \"After long striving they will come\nTo blood; and the wild party from the woods\nWill chase the other with much injury forth.\nThen it behoves, that this must fall, within\nThree solar circles; and the other rise\nBy borrow\'d force of one, who under shore\nNow rests.  It shall a long space hold aloof\nIts forehead, keeping under heavy weight\nThe other oppress\'d, indignant at the load,\nAnd grieving sore.  The just are two in number,\nBut they neglected.  Av\'rice, envy, pride,\nThree fatal sparks, have set the hearts of all\nOn fire.\"  Here ceas\'d the lamentable sound;\nAnd I continu\'d thus: \"Still would I learn\nMore from thee, farther parley still entreat.\nOf Farinata and Tegghiaio say,\nThey who so well deserv\'d, of Giacopo,\nArrigo, Mosca, and the rest, who bent\nTheir minds on working good.  Oh!  tell me where\nThey bide, and to their knowledge let me come.\nFor I am press\'d with keen desire to hear,\nIf heaven\'s sweet cup or poisonous drug of hell\nBe to their lip assign\'d.\"   He answer\'d straight:\n\"These are yet blacker spirits.  Various crimes\nHave sunk them deeper in the dark abyss.\nIf thou so far descendest, thou mayst see them.\nBut to the pleasant world when thou return\'st,\nOf me make mention, I entreat thee, there.\nNo more I tell thee, answer thee no more.\"\n     This said, his fixed eyes he turn\'d askance,\nA little ey\'d me, then bent down his head,\nAnd \'midst his blind companions with it fell.\n     When thus my guide:  \"No more his bed he leaves,\nEre the last angel-trumpet blow.  The Power\nAdverse to these shall then in glory come,\nEach one forthwith to his sad tomb repair,\nResume his fleshly vesture and his form,\nAnd hear the eternal d");
    strcat(expected_filecontent, "oom re-echoing rend\nThe vault.\"  So pass\'d we through that mixture foul\nOf spirits and rain, with tardy steps; meanwhile\nTouching, though slightly, on the life to come.\nFor thus I question\'d:  \"Shall these tortures, Sir!\nWhen the great sentence passes, be increas\'d,\nOr mitigated, or as now severe?\"\n     He then:  \"Consult thy knowledge; that decides\nThat as each thing to more perfection grows,\nIt feels more sensibly both good and pain.\nThough ne\'er to true perfection may arrive\nThis race accurs\'d, yet nearer then than now\nThey shall approach it.\"  Compassing that path\nCircuitous we journeyed, and discourse\nMuch more than I relate between us pass\'d:\nTill at the point, where the steps led below,\nArriv\'d, there Plutus, the great foe, we found.\n\n\n\nCANTO VII\n\n\"AH me!  O Satan!  Satan!\" loud exclaim\'d\nPlutus, in accent hoarse of wild alarm:\nAnd the kind sage, whom no event surpris\'d,\nTo comfort me thus spake:  \"Let not thy fear\nHarm thee, for power in him, be sure, is none\nTo hinder down this rock thy safe descent.\"\nThen to that sworn lip turning, \" Peace!\"  he cried,\n\"Curs\'d wolf!  thy fury inward on thyself\nPrey, and consume thee!  Through the dark profound\nNot without cause he passes.  So \'t is will\'d\nOn high, there where the great Archangel pour\'d\nHeav\'n\'s vengeance on the first adulterer proud.\"\n     As sails full spread and bellying with the wind\nDrop suddenly collaps\'d, if the mast split;\nSo to the ground down dropp\'d the cruel fiend.\n     Thus we, descending to the fourth steep ledge,\nGain\'d on the dismal shore, that all the woe\nHems in of all the universe.  Ah me!\nAlmighty Justice!  in what store thou heap\'st\nNew pains, new troubles, as I here beheld!\nWherefore doth fault of ours bring us to this?\n     E\'en as a billow, on Charybdis rising,\nAgainst encounter\'d billow dashing breaks;\nSuch is the dance this w");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "YOUNG.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5936; ++i)
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
//  Test 29: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[128] = "";

                strcat(expected_filecontent, "rite, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as sh");

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "NEIGHBOR");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 127; ++i)
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
//  Test 30: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(5722, 1);
            char expected_filecontent[5723] = "";

            strcat(expected_filecontent, "f Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if ");
    strcat(expected_filecontent, "it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rustic");

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WHOLE.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 476; ++i)
            {
                int res = file_read(filecontent + 12 * i, 12, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 12 * i, 12, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5722);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 5722);

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
//  Test 31: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(425, 1);
    char *filecontent1 = (char *)calloc(6556, 1);
    char *filecontent2 = (char *)calloc(7928, 1);
    char *filecontent3 = (char *)calloc(7816, 1);
    char *filecontent4 = (char *)calloc(5722, 1);
    char *filecontent5 = (char *)calloc(6144, 1);
    char *filecontent6 = (char *)calloc(5936, 1);
    char *filecontent7 = (char *)calloc(127, 1);

            char expected_filecontent0[426] = "";
    char expected_filecontent1[6557] = "";
    char expected_filecontent2[7929] = "";
    char expected_filecontent3[7817] = "";
    char expected_filecontent4[5723] = "";
    char expected_filecontent5[6145] = "";
    char expected_filecontent6[5937] = "";
    char expected_filecontent7[128] = "";

            strcat(expected_filecontent0, " farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW");strcat(expected_filecontent1, "rd tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer known,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit down a precipice,\nWhere space enough to lodge a thousand spreads;\nThus downward from a craggy steep we found,\nThat this dark wave resounded, roaring loud,\nSo that the ear its clamour soon had stunn\'d.\n     I had a cord that brac\'d my girdle round,\nWherewith I erst had thought fast bound to take\nThe painted leopard.  This when I had all\nUnloosen\'d from me (so my master bade)\nI gather\'d up, and stretch\'d it forth to him.\nThen to the right he turn\'d, and from the brink\nStanding few paces distant, cast it down\nInto the deep abyss.  \"And somewhat strange,\"\nThus to myself I spake, \"signal so strange\nBetokens, which my guide with earnest eye\nThus follows.\"  Ah! what caution must men use\nWith those who look not at the deed alone,\nBut spy into the thoughts with subtle skill!\n     \"Quickly shall come,\" he said, \"what I expect,\nThine eye discover quickly, that whereof\nThy thought is dreaming.\"  Ever to that truth,\nWhich but the semblance of a falsehood wears,\nA man, if possible, should bar his lip;\nSince, although blameless, he incurs reproach.\nBut silence here were vain; and by these notes\nWhich now I sing, reader!  I swear to thee,\nSo may they favour find to latest times!\nThat through the gross and murky air I spied\nA shape come swimming up, that might have quell\'d\nThe stoutest heart with wonder, in such guise\nAs one returns, who hath been down to loose\nAn anchor grappled fast against some rock,\nOr to aught else that in the salt wave lies,\nWho upward springing close draws in his feet.\n\n\n\nCANTO XVII\n\n\"LO! the fell monster with the deadly sting!\nWho passes mountains, breaks through fenced walls\nAnd firm embattled spears, and with his filth\nTaints all the world!\"  Thus me my guide address\'d,\nAnd beckon\'d him, that he should come to shore,\nNear to the stony causeway\'s utmost edge.\n     Forthwith that image vile of fraud appear\'d,\nHis head and upper part expos\'d on land,\nBut laid not on the shore his bestial train.\nHis face the semblance of a just man\'s wore,\nSo kind and gracious was its outward cheer;\nThe rest was serpent all:  two shaggy claws\nReach\'d to the armpits, and the back and breast,\nAnd either side, were painted o\'er with nodes\nAnd orbits.  Colours variegated more\nNor Turks nor Tartars e\'er on cloth of state\nWith interchangeable embroidery wove,\nNor spread Arachne o\'er her curious loom.\nAs ofttimes a light skiff, moor\'d to the shore,\nStands part in water, part upon the land;\nOr, a");
    strcat(expected_filecontent1, "s where dwells the greedy German boor,\nThe beaver settles watching for his prey;\nSo on the rim, that fenc\'d the sand with rock,\nSat perch\'d the fiend of evil.  In the void\nGlancing, his tail upturn\'d its venomous fork,\nWith sting like scorpion\'s arm\'d.  Then thus my guide:\n\"Now need our way must turn few steps apart,\nFar as to that ill beast, who couches there.\"\n     Thereat toward the right our downward course\nWe shap\'d, and, better to escape the flame\nAnd burning marle, ten paces on the verge\nProceeded.  Soon as we to him arrive,\nA little further on mine eye beholds\nA tribe of spirits, seated on the sand\nNear the wide chasm.  Forthwith my master spake:\n\"That to the full thy knowledge may extend\nOf all this round contains, go now, and mark\nThe mien these wear:  but hold not long discourse.\nTill thou returnest, I with him meantime\nWill parley, that to us he may vouchsafe\nThe aid of his strong shoulders.\"  Thus alone\nYet forward on the\' extremity I pac\'d\nOf that seventh circle, where the mournful tribe\nWere seated.  At the eyes forth gush\'d their pangs.\nAgainst the vapours and the torrid soil\nAlternately their shifting hands they plied.\nThus use the dogs in summer still to ply\nTheir jaws and feet by turns, when bitten sore\nBy gnats, or flies, or gadflies swarming round.\n     Noting the visages of some, who lay\nBeneath the pelting of that dolorous fire,\nOne of them all I knew not; but perceiv\'d,\nThat pendent from his neck each bore a pouch\nWith colours and with emblems various mark\'d,\nOn which it seem\'d as if their eye did feed.\n     And when amongst them looking round I came,\nA yellow purse I saw with azure wrought,\nThat wore a lion\'s countenance and port.\nThen still my sight pursuing its career,\nAnother I beheld, than blood more red.\nA goose display of whiter wing than curd.\nAnd one, who bore a fat and azure swine\nPictur\'d on his white scrip, addressed me thus:\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they thunder in mine ears, exclaiming\n\"O haste that noble knight! he who the pouch\nWith the three beaks will bring!\"  This said, he writh\'d\nThe mouth, and loll\'d the tongue out, like an ox\nThat licks his nostrils.  I, lest longer stay\nHe ill might brook, who bade me stay not long,\nBackward my steps from those sad spirits turn\'d.\n     My guide already seated on the haunch\nOf the fierce animal");strcat(expected_filecontent2, ", and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light\nOf gladness that is in them, well to scan,\nThose yonder three, of deeper ken than ours,\nThy sight shall quicken.\"  Thus began their song;\nAnd then they led me to the Gryphon\'s breast,\nWhile, turn\'d toward us, Beatrice stood.\n\"Spare not thy vision.  We have stationed thee\nBefore the emeralds, whence love erewhile\nHath drawn his weapons on thee.  \"As they spake,\nA thousand fervent wishes riveted\nMine eyes upon her beaming eyes, that stood\nStill fix\'d toward the Gryphon motionless.\nAs the sun strikes a mirror, even thus\nWithin those orbs the twofold being, shone,\nFor ever varying, in one figure now\nReflected, now in other.  Reader!  muse\nHow wond\'rous in my sight it seem\'d to mark\nA thing, albeit steadfast in itself,\nYet in its imag\'d semblance mutable.\n     Full of amaze, and joyous, while my soul\nFed on the viand, whereof still desire\nGrows with satiety, the other three\nWith gesture, that declar\'d a loftier line,\nAdvanc\'d: to their own carol on they came\nDancing in festive ring angelical.\n     \"Turn, Beatrice!\" was their song:  \"O turn\nThy saintly sight on this thy faithful one,\nWho to behold thee many a wearisome pace\nHath measur\'d.  Gracious at our pray\'r vouchsafe\nUnveil to him thy cheeks: that he may mark\nThy second beauty, now conceal\'d.\"  O splendour!\nO sacred light eternal!  who is he\nSo pale with musing in Pierian shades,\nOr with that fount so lavishly imbued,\nWhose spirit should not fail him in th\' essay\nTo represent thee such as thou didst seem,\nWhen under cope of the still-chiming heaven\nThou gav\'st to open air thy charms reveal\'d.\n\n\n\nCANTO XXXII\n\nMine eyes with such an eager coveting,\nWere bent to rid them of their ten years\' thirst,\nNo other sense was waking: and e\'en they\nWere fenc\'d on either side from heed of aught;\nSo tangled in its custom\'d toils that smile\nOf saintly brightness drew me to itself,\nWhen forcibly toward the left my sight\nThe sacred virgins turn\'d; for from their lips\nI heard the warning sounds:  \"Too fix\'d a gaze!\"\n     Awhile my vision labor\'d; as when late\nUpon the\' o\'erstrained eyes the sun hath smote:\nBut soon to lesser object, as the view\nWas now recover\'d (lesser in respect\nTo that excess of sensible, whence late\n");
    strcat(expected_filecontent2, "I had perforce been sunder\'d) on their right\nI mark\'d that glorious army wheel, and turn,\nAgainst the sun and sev\'nfold lights, their front.\nAs when, their bucklers for protection rais\'d,\nA well-rang\'d troop, with portly banners curl\'d,\nWheel circling, ere the whole can change their ground:\nE\'en thus the goodly regiment of heav\'n\nProceeding, all did pass us, ere the car\nHad slop\'d his beam.  Attendant at the wheels\nThe damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we mov\'d, as far\nPerchance as arrow at three several flights\nFull wing\'d had sped, when from her station down\nDescended Beatrice.  With one voice\nAll murmur\'d  \"Adam,\" circling next a plant\nDespoil\'d of flowers and leaf on every bough.\nIts tresses, spreading more as more they rose,\nWere such, as \'midst their forest wilds for height\nThe Indians might have gaz\'d at.  \"Blessed thou!\nGryphon, whose beak hath never pluck\'d that tree\nPleasant to taste: for hence the appetite\nWas warp\'d to evil.\"  Round the stately trunk\nThus shouted forth the rest, to whom return\'d\nThe animal twice-gender\'d:  \"Yea: for so\nThe generation of the just are sav\'d.\"\nAnd turning to the chariot-pole, to foot\nHe drew it of the widow\'d branch, and bound\nThere left unto the stock whereon it grew.\n     As when large floods of radiance from above\nStream, with that radiance mingled, which ascends\nNext after setting of the scaly sign,\nOur plants then burgeon, and each wears anew\nHis wonted colours, ere the sun have yok\'d\nBeneath another star his flamy steeds;\nThus putting forth a hue, more faint than rose,\nAnd deeper than the violet, was renew\'d\nThe plant, erewhile in all its branches bare.\n     Unearthly was the hymn, which then arose.\nI understood it not, nor to the end\nEndur\'d the harmony.  Had I the skill\nTo pencil forth, how clos\'d th\' unpitying eyes\nSlumb\'ring, when Syrinx warbled, (eyes that paid\nSo dearly for their watching,) then like painter,\nThat with a model paints, I might design\nThe manner of my falling into sleep.\nBut feign who will the slumber cunningly;\nI pass it by to when I wak\'d, and tell\nHow suddenly a flash of splendour rent\nThe curtain of my sleep, and one cries out:\n\"Arise, what dost thou?\"  As the chosen three,\nOn Tabor\'s mount, admitted to behold\nThe blossoming of that fair tree, whose fruit\nIs coveted of angels, and doth make\nPerpetual feast in heaven, to themselves\nReturning at the word, whence deeper sleeps\nWere broken, that they their tribe diminish\'d saw,\nBoth Moses and Elias gone, and chang\'d\nThe stole their master wore: thus to myself\nReturning, over me beheld I stand\nThe piteous one, who cross the stream had brought\nMy steps.  \"And where,\" all doubting, I exclaim\'d,\n\"Is Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nT");strcat(expected_filecontent3, "eriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose fair height my lady\'s eyes did lift me,\nAnd after through this heav\'n from light to light,\nHave I learnt that, which if I tell again,\nIt may with many woefully disrelish;\nAnd, if I am a timid friend to truth,\nI fear my life may perish among those,\nTo whom these days shall be of ancient date.\"\n     The brightness, where enclos\'d the treasure smil\'d,\nWhich I had found there, first shone glisteningly,\nLike to a golden mirror in the sun;\nNext answer\'d:  \"Conscience, dimm\'d or by its own\nOr other\'s shame, will feel thy saying sharp.\nThou, notwithstanding, all deceit remov\'d,\nSee the whole vision be made manifest.\nAnd let them wince who have their withers wrung.\nWhat though, when tasted first, thy voice shall prove\nUnwelcome, on digestion it will turn\nTo vital nourishment.  The cry thou raisest,\nShall, as the wind doth, smite the proudest summits;\nWhich is of honour no light argument,\nFor this there only have been shown to thee,\nThroughout these orbs, the mountain, and the deep,\nSpirits, whom fame hath note of");
    strcat(expected_filecontent3, ".  For the mind\nOf him, who hears, is loth to acquiesce\nAnd fix its faith, unless the instance brought\nBe palpable, and proof apparent urge.\"\n\n\n\nCANTO XVIII\n\nNow in his word, sole, ruminating, joy\'d\nThat blessed spirit; and I fed on mine,\nTempting the sweet with bitter:  she meanwhile,\nWho led me unto God, admonish\'d:  \"Muse\nOn other thoughts: bethink thee, that near Him\nI dwell, who recompenseth every wrong.\"\n     At the sweet sounds of comfort straight I turn\'d;\nAnd, in the saintly eyes what love was seen,\nI leave in silence here:  nor through distrust\nOf my words only, but that to such bliss\nThe mind remounts not without aid.  Thus much\nYet may I speak; that, as I gaz\'d on her,\nAffection found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-f");strcat(expected_filecontent4, "f Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if ");
    strcat(expected_filecontent4, "it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rustic");strcat(expected_filecontent5, "ceeding,\nAs it hath grave beyond its virtue great.\nOur shape, regarmented with glorious weeds\nOf saintly flesh, must, being thus entire,\nShow yet more gracious.  Therefore shall increase,\nWhate\'er of light, gratuitous, imparts\nThe Supreme Good; light, ministering aid,\nThe better disclose his glory: whence\nThe vision needs increasing, much increase\nThe fervour, which it kindles; and that too\nThe ray, that comes from it.  But as the greed\nWhich gives out flame, yet it its whiteness shines\nMore lively than that, and so preserves\nIts proper semblance; thus this circling sphere\nOf splendour, shall to view less radiant seem,\nThan shall our fleshly robe, which yonder earth\nNow covers.  Nor will such excess of light\nO\'erpower us, in corporeal organs made\nFirm, and susceptible of all delight.\"\n     So ready and so cordial an \"Amen,\"\nFollowed from either choir, as plainly spoke\nDesire of their dead bodies; yet perchance\nNot for themselves, but for their kindred dear,\nMothers and sires, and those whom best they lov\'d,\nEre they were made imperishable flame.\n     And lo!  forthwith there rose up round about\nA lustre over that already there,\nOf equal clearness, like the brightening up\nOf the horizon.  As at an evening hour\nOf twilight, new appearances through heav\'n\nPeer with faint glimmer, doubtfully descried;\nSo there new substances, methought began\nTo rise in view; and round the other twain\nEnwheeling, sweep their ampler circuit wide.\n     O gentle glitter of eternal beam!\nWith what a such whiteness did it flow,\nO\'erpowering vision in me!  But so fair,\nSo passing lovely, Beatrice show\'d,\nMind cannot follow it, nor words express\nHer infinite sweetness.  Thence mine eyes regain\'d\nPower to look up, and I beheld myself,\nSole with my lady, to more lofty bliss\nTranslated:  for the star, with warmer smile\nImpurpled, well denoted our ascent.\n     With all the heart, and with that tongue which speaks\nThe same in all, an holocaust I made\nTo God, befitting the new grace vouchsaf\'d.\nAnd from my bosom had not yet upsteam\'d\nThe fuming of that incense, when I knew\nThe rite accepted.  With such mighty sheen\nAnd mantling crimson, in two listed rays\nThe splendours shot before me, that I cried,\n\"God of Sabaoth!  that does prank them thus!\"\n     As leads the galaxy from pole to pole,\nDistinguish\'d into greater lights and less,\nIts pathway, which the wisest fail to spell;\nSo thickly studded, in the depth of Mars,\nThose rays describ\'d the venerable sign,\nThat quadrants in the round conjoining frame.\nHere memory mocks the toil of genius.  Christ\nBeam\'d on that cross; and pattern fails me now.\nBut whoso takes his cross, and follows Christ\nWill pardon me for that I leave untold,\nWhen in the flecker\'d dawning he shall spy\nThe glitterance of Christ.  From horn to horn,\nAnd \'tween the summit and the base did move\nLights, scintillating, as they met and pass\'d.\nThus oft are seen, with ever-changeful glance,\nStraight or athwart, now rapid and now slow,\nThe atomies of bodies, long or short,\nTo move along the sunbeam, whose slant line\nCheckers the shadow, interpos\'d by art\nAgainst the noontide heat.  And as the chime\nOf minstrel music, dulcimer, and help\nWith many strings, a pleasant dining makes\nTo him, who heareth not distinct the note;\nSo from the lights, which there appear\'d to me,\nGather\'d along the cross a melody,\nThat, indistinctly heard, with ravishment\nPossess\'d me.  Yet I mark\'d it was a hymn\nOf lofty praises; for there came to me\n\"Arise and conquer,\" as to one who hears\nAnd comprehends not.  Me such ecstasy\nO\'ercame, that never till that hour was thing\nThat held me in so sweet imprisonment.\n     Perhaps my saying over bold appears,\nAccounting less the pleasure of those eyes,\nWhereon to look fulfilleth all desire.\nBut he, who is aware those living seals\nOf every beauty work with quicker force,\nThe higher they are ris\'n; and that there\nI had not turn\'d me to them; he may well\nExcuse me that, whereof in my excuse\nI do accuse me, and may own my truth;\nThat holy pleasure here not yet reveal\'d,\nWhich grows in transport as we mount aloof.\n\n\n\nCANTO XV\n\nTrue lo");
    strcat(expected_filecontent5, "ve, that ever shows itself as clear\nIn kindness, as loose appetite in wrong,\nSilenced that lyre harmonious, and still\'d\nThe sacred chords, that are by heav\'n\'s right hand\nUnwound and tighten\'d, flow to righteous prayers\nShould they not hearken, who, to give me will\nFor praying, in accordance thus were mute?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the s");strcat(expected_filecontent6, "leety flaw\nThrough the dun midnight air stream\'d down amain:\nStank all the land whereon that tempest fell.\n     Cerberus, cruel monster, fierce and strange,\nThrough his wide threefold throat barks as a dog\nOver the multitude immers\'d beneath.\nHis eyes glare crimson, black his unctuous beard,\nHis belly large, and claw\'d the hands, with which\nHe tears the spirits, flays them, and their limbs\nPiecemeal disparts.  Howling there spread, as curs,\nUnder the rainy deluge, with one side\nThe other screening, oft they roll them round,\nA wretched, godless crew.  When that great worm\nDescried us, savage Cerberus, he op\'d\nHis jaws, and the fangs show\'d us; not a limb\nOf him but trembled.  Then my guide, his palms\nExpanding on the ground, thence filled with earth\nRais\'d them, and cast it in his ravenous maw.\nE\'en as a dog, that yelling bays for food\nHis keeper, when the morsel comes, lets fall\nHis fury, bent alone with eager haste\nTo swallow it; so dropp\'d the loathsome cheeks\nOf demon Cerberus, who thund\'ring stuns\nThe spirits, that they for deafness wish in vain.\n     We, o\'er the shades thrown prostrate by the brunt\nOf the heavy tempest passing, set our feet\nUpon their emptiness, that substance seem\'d.\n     They all along the earth extended lay\nSave one, that sudden rais\'d himself to sit,\nSoon as that way he saw us pass.  \"O thou!\"\nHe cried, \"who through the infernal shades art led,\nOwn, if again thou know\'st me.  Thou wast fram\'d\nOr ere my frame was broken.\"  I replied:\n\"The anguish thou endur\'st perchance so takes\nThy form from my remembrance, that it seems\nAs if I saw thee never.  But inform\nMe who thou art, that in a place so sad\nArt set, and in such torment, that although\nOther be greater, more disgustful none\nCan be imagin\'d.\"  He in answer thus:\n\"Thy city heap\'d with envy to the brim,\nAy that the measure overflows its bounds,\nHeld me in brighter days.  Ye citizens\nWere wont to name me Ciacco.  For the sin\nOf glutt\'ny, damned vice, beneath this rain,\nE\'en as thou see\'st, I with fatigue am worn;\nNor I sole spirit in this woe:  all these\nHave by like crime incurr\'d like punishment.\"\n     No more he said, and I my speech resum\'d:\n\"Ciacco!  thy dire affliction grieves me much,\nEven to tears.  But tell me, if thou know\'st,\nWhat shall at length befall the citizens\nOf the divided city;  whether any just one\nInhabit there:  and tell me of the cause,\nWhence jarring discord hath assail\'d it thus?\"\n     He then: \"After long striving they will come\nTo blood; and the wild party from the woods\nWill chase the other with much injury forth.\nThen it behoves, that this must fall, within\nThree solar circles; and the other rise\nBy borrow\'d force of one, who under shore\nNow rests.  It shall a long space hold aloof\nIts forehead, keeping under heavy weight\nThe other oppress\'d, indignant at the load,\nAnd grieving sore.  The just are two in number,\nBut they neglected.  Av\'rice, envy, pride,\nThree fatal sparks, have set the hearts of all\nOn fire.\"  Here ceas\'d the lamentable sound;\nAnd I continu\'d thus: \"Still would I learn\nMore from thee, farther parley still entreat.\nOf Farinata and Tegghiaio say,\nThey who so well deserv\'d, of Giacopo,\nArrigo, Mosca, and the rest, who bent\nTheir minds on working good.  Oh!  tell me where\nThey bide, and to their knowledge let me come.\nFor I am press\'d with keen desire to hear,\nIf heaven\'s sweet cup or poisonous drug of hell\nBe to their lip assign\'d.\"   He answer\'d straight:\n\"These are yet blacker spirits.  Various crimes\nHave sunk them deeper in the dark abyss.\nIf thou so far descendest, thou mayst see them.\nBut to the pleasant world when thou return\'st,\nOf me make mention, I entreat thee, there.\nNo more I tell thee, answer thee no more.\"\n     This said, his fixed eyes he turn\'d askance,\nA little ey\'d me, then bent down his head,\nAnd \'midst his blind companions with it fell.\n     When thus my guide:  \"No more his bed he leaves,\nEre the last angel-trumpet blow.  The Power\nAdverse to these shall then in glory come,\nEach one forthwith to his sad tomb repair,\nResume his fleshly vesture and his form,\nAnd hear the eternal d");
    strcat(expected_filecontent6, "oom re-echoing rend\nThe vault.\"  So pass\'d we through that mixture foul\nOf spirits and rain, with tardy steps; meanwhile\nTouching, though slightly, on the life to come.\nFor thus I question\'d:  \"Shall these tortures, Sir!\nWhen the great sentence passes, be increas\'d,\nOr mitigated, or as now severe?\"\n     He then:  \"Consult thy knowledge; that decides\nThat as each thing to more perfection grows,\nIt feels more sensibly both good and pain.\nThough ne\'er to true perfection may arrive\nThis race accurs\'d, yet nearer then than now\nThey shall approach it.\"  Compassing that path\nCircuitous we journeyed, and discourse\nMuch more than I relate between us pass\'d:\nTill at the point, where the steps led below,\nArriv\'d, there Plutus, the great foe, we found.\n\n\n\nCANTO VII\n\n\"AH me!  O Satan!  Satan!\" loud exclaim\'d\nPlutus, in accent hoarse of wild alarm:\nAnd the kind sage, whom no event surpris\'d,\nTo comfort me thus spake:  \"Let not thy fear\nHarm thee, for power in him, be sure, is none\nTo hinder down this rock thy safe descent.\"\nThen to that sworn lip turning, \" Peace!\"  he cried,\n\"Curs\'d wolf!  thy fury inward on thyself\nPrey, and consume thee!  Through the dark profound\nNot without cause he passes.  So \'t is will\'d\nOn high, there where the great Archangel pour\'d\nHeav\'n\'s vengeance on the first adulterer proud.\"\n     As sails full spread and bellying with the wind\nDrop suddenly collaps\'d, if the mast split;\nSo to the ground down dropp\'d the cruel fiend.\n     Thus we, descending to the fourth steep ledge,\nGain\'d on the dismal shore, that all the woe\nHems in of all the universe.  Ah me!\nAlmighty Justice!  in what store thou heap\'st\nNew pains, new troubles, as I here beheld!\nWherefore doth fault of ours bring us to this?\n     E\'en as a billow, on Charybdis rising,\nAgainst encounter\'d billow dashing breaks;\nSuch is the dance this w");strcat(expected_filecontent7, "rite, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as sh");


            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "SKY.TX");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "PAINT.BIN");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "SOFT.TXT");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "DROP.TXT");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "WHOLE.TXT");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "MAP");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "YOUNG.BIN");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file7 = file_open(volume, "NEIGHBOR");
                    test_error(file7 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 425, file0);
                test_error(size0 == 425, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 425 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 425);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 425);
            
                size_t size1 = file_read(filecontent1, 1, 6556, file1);
                test_error(size1 == 6556, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6556 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 6556);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 6556);
            
                size_t size2 = file_read(filecontent2, 1, 7928, file2);
                test_error(size2 == 7928, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7928 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 7928);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 7928);
            
                size_t size3 = file_read(filecontent3, 1, 7816, file3);
                test_error(size3 == 7816, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7816 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 7816);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 7816);
            
                size_t size4 = file_read(filecontent4, 1, 5722, file4);
                test_error(size4 == 5722, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5722 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 5722);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 5722);
            
                size_t size5 = file_read(filecontent5, 1, 6144, file5);
                test_error(size5 == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 6144);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 6144);
            
                size_t size6 = file_read(filecontent6, 1, 5936, file6);
                test_error(size6 == 5936, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5936 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 5936);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 5936);
            
                size_t size7 = file_read(filecontent7, 1, 127, file7);
                test_error(size7 == 127, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 127 bajtów, a wczytała %lu", size7);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos7 = mem_find_first_difference(filecontent7, expected_filecontent7, 127);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos7 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos7, mem_get_byte(filecontent7, diff_pos7), mem_get_byte(expected_filecontent7, diff_pos7));
        
                onerror_compare_memory(expected_filecontent7, filecontent7, 127);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);
    free(filecontent7);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);
    file_close(file7);


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
//  Test 32: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(5936, 1);
            char expected_filecontent[5937] = "";

            strcat(expected_filecontent, "leety flaw\nThrough the dun midnight air stream\'d down amain:\nStank all the land whereon that tempest fell.\n     Cerberus, cruel monster, fierce and strange,\nThrough his wide threefold throat barks as a dog\nOver the multitude immers\'d beneath.\nHis eyes glare crimson, black his unctuous beard,\nHis belly large, and claw\'d the hands, with which\nHe tears the spirits, flays them, and their limbs\nPiecemeal disparts.  Howling there spread, as curs,\nUnder the rainy deluge, with one side\nThe other screening, oft they roll them round,\nA wretched, godless crew.  When that great worm\nDescried us, savage Cerberus, he op\'d\nHis jaws, and the fangs show\'d us; not a limb\nOf him but trembled.  Then my guide, his palms\nExpanding on the ground, thence filled with earth\nRais\'d them, and cast it in his ravenous maw.\nE\'en as a dog, that yelling bays for food\nHis keeper, when the morsel comes, lets fall\nHis fury, bent alone with eager haste\nTo swallow it; so dropp\'d the loathsome cheeks\nOf demon Cerberus, who thund\'ring stuns\nThe spirits, that they for deafness wish in vain.\n     We, o\'er the shades thrown prostrate by the brunt\nOf the heavy tempest passing, set our feet\nUpon their emptiness, that substance seem\'d.\n     They all along the earth extended lay\nSave one, that sudden rais\'d himself to sit,\nSoon as that way he saw us pass.  \"O thou!\"\nHe cried, \"who through the infernal shades art led,\nOwn, if again thou know\'st me.  Thou wast fram\'d\nOr ere my frame was broken.\"  I replied:\n\"The anguish thou endur\'st perchance so takes\nThy form from my remembrance, that it seems\nAs if I saw thee never.  But inform\nMe who thou art, that in a place so sad\nArt set, and in such torment, that although\nOther be greater, more disgustful none\nCan be imagin\'d.\"  He in answer thus:\n\"Thy city heap\'d with envy to the brim,\nAy that the measure overflows its bounds,\nHeld me in brighter days.  Ye citizens\nWere wont to name me Ciacco.  For the sin\nOf glutt\'ny, damned vice, beneath this rain,\nE\'en as thou see\'st, I with fatigue am worn;\nNor I sole spirit in this woe:  all these\nHave by like crime incurr\'d like punishment.\"\n     No more he said, and I my speech resum\'d:\n\"Ciacco!  thy dire affliction grieves me much,\nEven to tears.  But tell me, if thou know\'st,\nWhat shall at length befall the citizens\nOf the divided city;  whether any just one\nInhabit there:  and tell me of the cause,\nWhence jarring discord hath assail\'d it thus?\"\n     He then: \"After long striving they will come\nTo blood; and the wild party from the woods\nWill chase the other with much injury forth.\nThen it behoves, that this must fall, within\nThree solar circles; and the other rise\nBy borrow\'d force of one, who under shore\nNow rests.  It shall a long space hold aloof\nIts forehead, keeping under heavy weight\nThe other oppress\'d, indignant at the load,\nAnd grieving sore.  The just are two in number,\nBut they neglected.  Av\'rice, envy, pride,\nThree fatal sparks, have set the hearts of all\nOn fire.\"  Here ceas\'d the lamentable sound;\nAnd I continu\'d thus: \"Still would I learn\nMore from thee, farther parley still entreat.\nOf Farinata and Tegghiaio say,\nThey who so well deserv\'d, of Giacopo,\nArrigo, Mosca, and the rest, who bent\nTheir minds on working good.  Oh!  tell me where\nThey bide, and to their knowledge let me come.\nFor I am press\'d with keen desire to hear,\nIf heaven\'s sweet cup or poisonous drug of hell\nBe to their lip assign\'d.\"   He answer\'d straight:\n\"These are yet blacker spirits.  Various crimes\nHave sunk them deeper in the dark abyss.\nIf thou so far descendest, thou mayst see them.\nBut to the pleasant world when thou return\'st,\nOf me make mention, I entreat thee, there.\nNo more I tell thee, answer thee no more.\"\n     This said, his fixed eyes he turn\'d askance,\nA little ey\'d me, then bent down his head,\nAnd \'midst his blind companions with it fell.\n     When thus my guide:  \"No more his bed he leaves,\nEre the last angel-trumpet blow.  The Power\nAdverse to these shall then in glory come,\nEach one forthwith to his sad tomb repair,\nResume his fleshly vesture and his form,\nAnd hear the eternal d");
    strcat(expected_filecontent, "oom re-echoing rend\nThe vault.\"  So pass\'d we through that mixture foul\nOf spirits and rain, with tardy steps; meanwhile\nTouching, though slightly, on the life to come.\nFor thus I question\'d:  \"Shall these tortures, Sir!\nWhen the great sentence passes, be increas\'d,\nOr mitigated, or as now severe?\"\n     He then:  \"Consult thy knowledge; that decides\nThat as each thing to more perfection grows,\nIt feels more sensibly both good and pain.\nThough ne\'er to true perfection may arrive\nThis race accurs\'d, yet nearer then than now\nThey shall approach it.\"  Compassing that path\nCircuitous we journeyed, and discourse\nMuch more than I relate between us pass\'d:\nTill at the point, where the steps led below,\nArriv\'d, there Plutus, the great foe, we found.\n\n\n\nCANTO VII\n\n\"AH me!  O Satan!  Satan!\" loud exclaim\'d\nPlutus, in accent hoarse of wild alarm:\nAnd the kind sage, whom no event surpris\'d,\nTo comfort me thus spake:  \"Let not thy fear\nHarm thee, for power in him, be sure, is none\nTo hinder down this rock thy safe descent.\"\nThen to that sworn lip turning, \" Peace!\"  he cried,\n\"Curs\'d wolf!  thy fury inward on thyself\nPrey, and consume thee!  Through the dark profound\nNot without cause he passes.  So \'t is will\'d\nOn high, there where the great Archangel pour\'d\nHeav\'n\'s vengeance on the first adulterer proud.\"\n     As sails full spread and bellying with the wind\nDrop suddenly collaps\'d, if the mast split;\nSo to the ground down dropp\'d the cruel fiend.\n     Thus we, descending to the fourth steep ledge,\nGain\'d on the dismal shore, that all the woe\nHems in of all the universe.  Ah me!\nAlmighty Justice!  in what store thou heap\'st\nNew pains, new troubles, as I here beheld!\nWherefore doth fault of ours bring us to this?\n     E\'en as a billow, on Charybdis rising,\nAgainst encounter\'d billow dashing breaks;\nSuch is the dance this w");

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "YOUNG.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 2465, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2465] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2465], c);

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
//  Test 33: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(5722, 1);
            char expected_filecontent[5723] = "";

            strcat(expected_filecontent, "f Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if ");
    strcat(expected_filecontent, "it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rustic");

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WHOLE.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -2799, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2923] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2923], c);

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
//  Test 34: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(7816, 1);
            char expected_filecontent[7817] = "";

            strcat(expected_filecontent, "eriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose fair height my lady\'s eyes did lift me,\nAnd after through this heav\'n from light to light,\nHave I learnt that, which if I tell again,\nIt may with many woefully disrelish;\nAnd, if I am a timid friend to truth,\nI fear my life may perish among those,\nTo whom these days shall be of ancient date.\"\n     The brightness, where enclos\'d the treasure smil\'d,\nWhich I had found there, first shone glisteningly,\nLike to a golden mirror in the sun;\nNext answer\'d:  \"Conscience, dimm\'d or by its own\nOr other\'s shame, will feel thy saying sharp.\nThou, notwithstanding, all deceit remov\'d,\nSee the whole vision be made manifest.\nAnd let them wince who have their withers wrung.\nWhat though, when tasted first, thy voice shall prove\nUnwelcome, on digestion it will turn\nTo vital nourishment.  The cry thou raisest,\nShall, as the wind doth, smite the proudest summits;\nWhich is of honour no light argument,\nFor this there only have been shown to thee,\nThroughout these orbs, the mountain, and the deep,\nSpirits, whom fame hath note of");
    strcat(expected_filecontent, ".  For the mind\nOf him, who hears, is loth to acquiesce\nAnd fix its faith, unless the instance brought\nBe palpable, and proof apparent urge.\"\n\n\n\nCANTO XVIII\n\nNow in his word, sole, ruminating, joy\'d\nThat blessed spirit; and I fed on mine,\nTempting the sweet with bitter:  she meanwhile,\nWho led me unto God, admonish\'d:  \"Muse\nOn other thoughts: bethink thee, that near Him\nI dwell, who recompenseth every wrong.\"\n     At the sweet sounds of comfort straight I turn\'d;\nAnd, in the saintly eyes what love was seen,\nI leave in silence here:  nor through distrust\nOf my words only, but that to such bliss\nThe mind remounts not without aid.  Thus much\nYet may I speak; that, as I gaz\'d on her,\nAffection found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-f");

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "DROP.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 685, SEEK_SET);
            file_seek(file, 5209, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[5894] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[5894], c);

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
    

                 struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BEHIND");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BEHIND) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WOULD");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WOULD) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "REASON");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (REASON) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BOUGHT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BOUGHT) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "VARY");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (VARY) jest nazwą katalogu, a nie pliku");
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
//  Test 40: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SPEEDFOR");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SPEEDFOR) jest nazwą katalogu, a nie pliku");
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
//  Test 41: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WAS.TXT");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie WAS.TXT, ponieważ nie istnieje on w katalogu głównym");
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
    

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "WAS.TXT");
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
//  Test 43: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
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
    

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
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
//  Test 45: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

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
//  Test 46: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SKY.TX");
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
//  Test 47: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[14] = { "SKY.TX", "PAINT.BIN", "SOFT.TXT", "DROP.TXT", "WHOLE.TXT", "MAP", "YOUNG.BIN", "NEIGHBOR", "BEHIND", "WOULD", "REASON", "BOUGHT", "VARY", "SPEEDFOR" };
            int found_names[14] = { 0 };

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
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
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SKY.TX");
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
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "PAINT.BIN");
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
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SOFT.TXT");
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
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "DROP.TXT");
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
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "WHOLE.TXT");
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
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "MAP");
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
//  Test 54: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST54(void)
{
    // informacje o teście
    test_start(54, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "YOUNG.BIN");
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
//  Test 55: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST55(void)
{
    // informacje o teście
    test_start(55, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "NEIGHBOR");
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
//  Test 56: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST56(void)
{
    // informacje o teście
    test_start(56, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("against_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "side");
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
            UTEST29, // Sprawdzanie poprawności działania funkcji file_read
            UTEST30, // Sprawdzanie poprawności działania funkcji file_read
            UTEST31, // Sprawdzanie poprawności działania funkcji file_read
            UTEST32, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST33, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST34, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_open
            UTEST41, // Sprawdzanie poprawności działania funkcji file_open
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji file_close
            UTEST46, // Sprawdzanie poprawności działania funkcji file_read
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST54, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST55, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST56, // Sprawdzanie poprawności działania funkcji dir_open
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
            test_summary(56); // wszystkie testy muszą zakończyć się sukcesem
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