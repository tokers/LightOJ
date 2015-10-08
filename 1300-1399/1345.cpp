/*************************************************************************
    > File Name: LightOJ1345.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月18日 星期五 21时50分58秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);

const int mod = 1e9 + 7;
//int dp[55][55][55][2];
int dp[55][55];

int main() {
/*	for (int n = 1; n <= 50; ++n) {
		for (int k = 1; k <= n; ++k) {
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; ++i) {
				dp[1][i - 1][1][k <= 1] = 1;
			}
			for (int i = 1; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					for (int l = 1; l <= k; ++l) {
						if (l < k) {
							bool flag = (l + 1 == k);
							for (int x = 1; x <= n - j - i; ++x) {
								dp[i + 1][j + x - 1][l + 1][flag] += dp[i][j][l][0];
								dp[i + 1][j + x - 1][l + 1][flag] %= mod;
								dp[i + 1][j + x - 1][l + 1][1] += dp[i][j][l][1];
								dp[i + 1][j + x - 1][l + 1][1] %= mod;
							}
						}
						for (int x = 1; x <= j; ++x) {
							dp[i + 1][j - x][1][1] += dp[i][j][l][1];
							dp[i + 1][j - x][1][1] %= mod;
							if (l != k) {
								dp[i + 1][j - x][1][0] += dp[i][j][l][0];
								dp[i + 1][j - x][1][0] %= mod;
							}
						}
					}
				}
			}
			int ans = 0;
			for (int i = 1; i <= k; ++i) {
				for (int j = 0; j < n; ++j) {
					ans += dp[n][j][i][1];
					ans %= mod;
				}
			}
			printf("dp[%d][%d] = %d;\n", n, k, ans);
		}
	}*/
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 4;
	dp[3][3] = 1;
	dp[4][1] = 1;
	dp[4][2] = 16;
	dp[4][3] = 6;
	dp[4][4] = 1;
	dp[5][1] = 1;
	dp[5][2] = 69;
	dp[5][3] = 41;
	dp[5][4] = 8;
	dp[5][5] = 1;
	dp[6][1] = 1;
	dp[6][2] = 348;
	dp[6][3] = 293;
	dp[6][4] = 67;
	dp[6][5] = 10;
	dp[6][6] = 1;
	dp[7][1] = 1;
	dp[7][2] = 2016;
	dp[7][3] = 2309;
	dp[7][4] = 602;
	dp[7][5] = 99;
	dp[7][6] = 12;
	dp[7][7] = 1;
	dp[8][1] = 1;
	dp[8][2] = 13357;
	dp[8][3] = 19975;
	dp[8][4] = 5811;
	dp[8][5] = 1024;
	dp[8][6] = 137;
	dp[8][7] = 14;
	dp[8][8] = 1;
	dp[9][1] = 1;
	dp[9][2] = 99376;
	dp[9][3] = 189524;
	dp[9][4] = 60875;
	dp[9][5] = 11304;
	dp[9][6] = 1602;
	dp[9][7] = 181;
	dp[9][8] = 16;
	dp[9][9] = 1;
	dp[10][1] = 1;
	dp[10][2] = 822040;
	dp[10][3] = 1960041;
	dp[10][4] = 690729;
	dp[10][5] = 133669;
	dp[10][6] = 19710;
	dp[10][7] = 2360;
	dp[10][8] = 231;
	dp[10][9] = 18;
	dp[10][10] = 1;
	dp[11][1] = 1;
	dp[11][2] = 7477161;
	dp[11][3] = 21993884;
	dp[11][4] = 8457285;
	dp[11][5] = 1695429;
	dp[11][6] = 257400;
	dp[11][7] = 32010;
	dp[11][8] = 3322;
	dp[11][9] = 287;
	dp[11][10] = 20;
	dp[11][11] = 1;
	dp[12][1] = 1;
	dp[12][2] = 74207208;
	dp[12][3] = 266361634;
	dp[12][4] = 111323149;
	dp[12][5] = 23023811;
	dp[12][6] = 3574957;
	dp[12][7] = 456720;
	dp[12][8] = 49236;
	dp[12][9] = 4512;
	dp[12][10] = 349;
	dp[12][11] = 22;
	dp[12][12] = 1;
	dp[13][1] = 1;
	dp[13][2] = 797771520;
	dp[13][3] = 465832349;
	dp[13][4] = 569068558;
	dp[13][5] = 333840443;
	dp[13][6] = 52785901;
	dp[13][7] = 6881160;
	dp[13][8] = 761904;
	dp[13][9] = 72540;
	dp[13][10] = 5954;
	dp[13][11] = 417;
	dp[13][12] = 24;
	dp[13][13] = 1;
	dp[14][1] = 1;
	dp[14][2] = 236662282;
	dp[14][3] = 245601640;
	dp[14][4] = 592425941;
	dp[14][5] = 153118119;
	dp[14][6] = 827242933;
	dp[14][7] = 109546009;
	dp[14][8] = 12372360;
	dp[14][9] = 1209936;
	dp[14][10] = 103194;
	dp[14][11] = 7672;
	dp[14][12] = 491;
	dp[14][13] = 26;
	dp[14][14] = 1;
	dp[15][1] = 1;
	dp[15][2] = 579018670;
	dp[15][3] = 756927692;
	dp[15][4] = 105854404;
	dp[15][5] = 426592033;
	dp[15][6] = 730434020;
	dp[15][7] = 841298052;
	dp[15][8] = 211170960;
	dp[15][9] = 21064680;
	dp[15][10] = 1845480;
	dp[15][11] = 142590;
	dp[15][12] = 9690;
	dp[15][13] = 571;
	dp[15][14] = 28;
	dp[15][15] = 1;
	dp[16][1] = 1;
	dp[16][2] = 103030220;
	dp[16][3] = 786804781;
	dp[16][4] = 313140867;
	dp[16][5] = 941331950;
	dp[16][6] = 806564102;
	dp[16][7] = 629877743;
	dp[16][8] = 788091430;
	dp[16][9] = 383685120;
	dp[16][10] = 34288800;
	dp[16][11] = 2721600;
	dp[16][12] = 192240;
	dp[16][13] = 12032;
	dp[16][14] = 657;
	dp[16][15] = 30;
	dp[16][16] = 1;
	dp[17][1] = 1;
	dp[17][2] = 681166799;
	dp[17][3] = 295334138;
	dp[17][4] = 480417536;
	dp[17][5] = 750800991;
	dp[17][6] = 251755782;
	dp[17][7] = 572224035;
	dp[17][8] = 356437546;
	dp[17][9] = 315701071;
	dp[17][10] = 663848640;
	dp[17][11] = 53749920;
	dp[17][12] = 3900480;
	dp[17][13] = 253776;
	dp[17][14] = 14722;
	dp[17][15] = 749;
	dp[17][16] = 32;
	dp[17][17] = 1;
	dp[18][1] = 1;
	dp[18][2] = 85861388;
	dp[18][3] = 618499591;
	dp[18][4] = 549759896;
	dp[18][5] = 122134104;
	dp[18][6] = 391024578;
	dp[18][7] = 667616013;
	dp[18][8] = 672712618;
	dp[18][9] = 957543966;
	dp[18][10] = 406178149;
	dp[18][11] = 102187513;
	dp[18][12] = 81591840;
	dp[18][13] = 5454144;
	dp[18][14] = 328950;
	dp[18][15] = 17784;
	dp[18][16] = 847;
	dp[18][17] = 34;
	dp[18][18] = 1;
	dp[19][1] = 1;
	dp[19][2] = 237021561;
	dp[19][3] = 104648418;
	dp[19][4] = 707831291;
	dp[19][5] = 96060144;
	dp[19][6] = 537015539;
	dp[19][7] = 61428842;
	dp[19][8] = 603056536;
	dp[19][9] = 416165905;
	dp[19][10] = 398536266;
	dp[19][11] = 500652959;
	dp[19][12] = 766525753;
	dp[19][13] = 120466080;
	dp[19][14] = 7465176;
	dp[19][15] = 419634;
	dp[19][16] = 21242;
	dp[19][17] = 951;
	dp[19][18] = 36;
	dp[19][19] = 1;
	dp[20][1] = 1;
	dp[20][2] = 95084561;
	dp[20][3] = 636315500;
	dp[20][4] = 682510411;
	dp[20][5] = 66543762;
	dp[20][6] = 586052016;
	dp[20][7] = 615853008;
	dp[20][8] = 323995067;
	dp[20][9] = 765151075;
	dp[20][10] = 593570238;
	dp[20][11] = 194863553;
	dp[20][12] = 656130927;
	dp[20][13] = 746068466;
	dp[20][14] = 173606040;
	dp[20][15] = 10027440;
	dp[20][16] = 527820;
	dp[20][17] = 25120;
	dp[20][18] = 1061;
	dp[20][19] = 38;
	dp[20][20] = 1;
	dp[21][1] = 1;
	dp[21][2] = 886212988;
	dp[21][3] = 881200710;
	dp[21][4] = 396033025;
	dp[21][5] = 12701413;
	dp[21][6] = 458731305;
	dp[21][7] = 372985702;
	dp[21][8] = 807113105;
	dp[21][9] = 35570540;
	dp[21][10] = 541544832;
	dp[21][11] = 910027867;
	dp[21][12] = 616684739;
	dp[21][13] = 739122112;
	dp[21][14] = 156079732;
	dp[21][15] = 244906200;
	dp[21][16] = 13246800;
	dp[21][17] = 655620;
	dp[21][18] = 29442;
	dp[21][19] = 1177;
	dp[21][20] = 40;
	dp[21][21] = 1;
	dp[22][1] = 1;
	dp[22][2] = 157108291;
	dp[22][3] = 437989986;
	dp[22][4] = 71441683;
	dp[22][5] = 642388598;
	dp[22][6] = 938181939;
	dp[22][7] = 135522921;
	dp[22][8] = 454658476;
	dp[22][9] = 221913791;
	dp[22][10] = 528686640;
	dp[22][11] = 13559581;
	dp[22][12] = 1642174;
	dp[22][13] = 837743827;
	dp[22][14] = 661518246;
	dp[22][15] = 143195478;
	dp[22][16] = 339006360;
	dp[22][17] = 17241840;
	dp[22][18] = 805266;
	dp[22][19] = 34232;
	dp[22][20] = 1299;
	dp[22][21] = 42;
	dp[22][22] = 1;
	dp[23][1] = 1;
	dp[23][2] = 802390665;
	dp[23][3] = 228700095;
	dp[23][4] = 966852050;
	dp[23][5] = 153938451;
	dp[23][6] = 175692673;
	dp[23][7] = 884160832;
	dp[23][8] = 945307660;
	dp[23][9] = 811238172;
	dp[23][10] = 688929393;
	dp[23][11] = 136122463;
	dp[23][12] = 33064254;
	dp[23][13] = 540429722;
	dp[23][14] = 453495267;
	dp[23][15] = 664455614;
	dp[23][16] = 891411704;
	dp[23][17] = 461380920;
	dp[23][18] = 22144584;
	dp[23][19] = 979110;
	dp[23][20] = 39514;
	dp[23][21] = 1427;
	dp[23][22] = 44;
	dp[23][23] = 1;
	dp[24][1] = 1;
	dp[24][2] = 29527948;
	dp[24][3] = 249305651;
	dp[24][4] = 101785883;
	dp[24][5] = 492132201;
	dp[24][6] = 802817114;
	dp[24][7] = 978430862;
	dp[24][8] = 193239331;
	dp[24][9] = 888547394;
	dp[24][10] = 620944146;
	dp[24][11] = 724490805;
	dp[24][12] = 677899989;
	dp[24][13] = 506037211;
	dp[24][14] = 609703432;
	dp[24][15] = 849965952;
	dp[24][16] = 656252087;
	dp[24][17] = 628788396;
	dp[24][18] = 618433200;
	dp[24][19] = 28101216;
	dp[24][20] = 1179624;
	dp[24][21] = 45312;
	dp[24][22] = 1561;
	dp[24][23] = 46;
	dp[24][24] = 1;
	dp[25][1] = 1;
	dp[25][2] = 524607135;
	dp[25][3] = 415689048;
	dp[25][4] = 902186784;
	dp[25][5] = 355100964;
	dp[25][6] = 198817129;
	dp[25][7] = 107206499;
	dp[25][8] = 990875991;
	dp[25][9] = 822649074;
	dp[25][10] = 373492836;
	dp[25][11] = 428194229;
	dp[25][12] = 999243658;
	dp[25][13] = 44029443;
	dp[25][14] = 388013094;
	dp[25][15] = 824931699;
	dp[25][16] = 965585471;
	dp[25][17] = 610869522;
	dp[25][18] = 634909481;
	dp[25][19] = 817594800;
	dp[25][20] = 35272800;
	dp[25][21] = 1409400;
	dp[25][22] = 51650;
	dp[25][23] = 1701;
	dp[25][24] = 48;
	dp[25][25] = 1;
	dp[26][1] = 1;
	dp[26][2] = 450555450;
	dp[26][3] = 117050952;
	dp[26][4] = 915971170;
	dp[26][5] = 58253347;
	dp[26][6] = 337099994;
	dp[26][7] = 576252003;
	dp[26][8] = 859945842;
	dp[26][9] = 814615770;
	dp[26][10] = 589820353;
	dp[26][11] = 162898278;
	dp[26][12] = 838394302;
	dp[26][13] = 354945576;
	dp[26][14] = 869452727;
	dp[26][15] = 418583118;
	dp[26][16] = 646590581;
	dp[26][17] = 52760383;
	dp[26][18] = 33715595;
	dp[26][19] = 249139032;
	dp[26][20] = 67429993;
	dp[26][21] = 43836000;
	dp[26][22] = 1671150;
	dp[26][23] = 58552;
	dp[26][24] = 1847;
	dp[26][25] = 50;
	dp[26][26] = 1;
	dp[27][1] = 1;
	dp[27][2] = 824150236;
	dp[27][3] = 177531219;
	dp[27][4] = 78140497;
	dp[27][5] = 626554444;
	dp[27][6] = 371199477;
	dp[27][7] = 692350233;
	dp[27][8] = 553080636;
	dp[27][9] = 355650992;
	dp[27][10] = 769227171;
	dp[27][11] = 231259212;
	dp[27][12] = 607416072;
	dp[27][13] = 17692601;
	dp[27][14] = 565256852;
	dp[27][15] = 501439573;
	dp[27][16] = 74895233;
	dp[27][17] = 18659220;
	dp[27][18] = 114189576;
	dp[27][19] = 501962055;
	dp[27][20] = 879714176;
	dp[27][21] = 377745193;
	dp[27][22] = 53983800;
	dp[27][23] = 1967706;
	dp[27][24] = 66042;
	dp[27][25] = 1999;
	dp[27][26] = 52;
	dp[27][27] = 1;
	dp[28][1] = 1;
	dp[28][2] = 559659630;
	dp[28][3] = 287828948;
	dp[28][4] = 821437957;
	dp[28][5] = 512569002;
	dp[28][6] = 156786818;
	dp[28][7] = 399430683;
	dp[28][8] = 891790180;
	dp[28][9] = 675501177;
	dp[28][10] = 277663700;
	dp[28][11] = 558188066;
	dp[28][12] = 718006802;
	dp[28][13] = 912343324;
	dp[28][14] = 308009883;
	dp[28][15] = 631780903;
	dp[28][16] = 371657207;
	dp[28][17] = 158067045;
	dp[28][18] = 905626576;
	dp[28][19] = 760768015;
	dp[28][20] = 286919162;
	dp[28][21] = 13714892;
	dp[28][22] = 759703393;
	dp[28][23] = 65926224;
	dp[28][24] = 2302020;
	dp[28][25] = 74144;
	dp[28][26] = 2157;
	dp[28][27] = 54;
	dp[28][28] = 1;
	dp[29][1] = 1;
	dp[29][2] = 946464936;
	dp[29][3] = 715728539;
	dp[29][4] = 945928197;
	dp[29][5] = 129538635;
	dp[29][6] = 850398315;
	dp[29][7] = 240543305;
	dp[29][8] = 761959783;
	dp[29][9] = 253058434;
	dp[29][10] = 540694949;
	dp[29][11] = 596746790;
	dp[29][12] = 757598689;
	dp[29][13] = 946329167;
	dp[29][14] = 867748610;
	dp[29][15] = 474361695;
	dp[29][16] = 741189090;
	dp[29][17] = 16602012;
	dp[29][18] = 804405983;
	dp[29][19] = 531358758;
	dp[29][20] = 313405370;
	dp[29][21] = 66369162;
	dp[29][22] = 227951194;
	dp[29][23] = 225943706;
	dp[29][24] = 79891056;
	dp[29][25] = 2677164;
	dp[29][26] = 82882;
	dp[29][27] = 2321;
	dp[29][28] = 56;
	dp[29][29] = 1;
	dp[30][1] = 1;
	dp[30][2] = 543403012;
	dp[30][3] = 734849095;
	dp[30][4] = 330921433;
	dp[30][5] = 28340421;
	dp[30][6] = 172059978;
	dp[30][7] = 461801965;
	dp[30][8] = 686972652;
	dp[30][9] = 71201416;
	dp[30][10] = 270709990;
	dp[30][11] = 310733550;
	dp[30][12] = 841551780;
	dp[30][13] = 100440295;
	dp[30][14] = 848403718;
	dp[30][15] = 657202225;
	dp[30][16] = 129577263;
	dp[30][17] = 477792529;
	dp[30][18] = 369243040;
	dp[30][19] = 13356840;
	dp[30][20] = 184652877;
	dp[30][21] = 50193736;
	dp[30][22] = 735124266;
	dp[30][23] = 200807788;
	dp[30][24] = 790705946;
	dp[30][25] = 96124560;
	dp[30][26] = 3096330;
	dp[30][27] = 92280;
	dp[30][28] = 2491;
	dp[30][29] = 58;
	dp[30][30] = 1;
	dp[31][1] = 1;
	dp[31][2] = 313942385;
	dp[31][3] = 874091051;
	dp[31][4] = 985076907;
	dp[31][5] = 497307364;
	dp[31][6] = 257621138;
	dp[31][7] = 220222680;
	dp[31][8] = 402835723;
	dp[31][9] = 461671722;
	dp[31][10] = 230082323;
	dp[31][11] = 306722144;
	dp[31][12] = 207301867;
	dp[31][13] = 981865967;
	dp[31][14] = 308346278;
	dp[31][15] = 382601704;
	dp[31][16] = 727941380;
	dp[31][17] = 183265540;
	dp[31][18] = 795509372;
	dp[31][19] = 664482598;
	dp[31][20] = 981486241;
	dp[31][21] = 388691385;
	dp[31][22] = 583095241;
	dp[31][23] = 322437662;
	dp[31][24] = 725086754;
	dp[31][25] = 469960179;
	dp[31][26] = 114892200;
	dp[31][27] = 3562830;
	dp[31][28] = 102362;
	dp[31][29] = 2667;
	dp[31][30] = 60;
	dp[31][31] = 1;
	dp[32][1] = 1;
	dp[32][2] = 970193548;
	dp[32][3] = 216238674;
	dp[32][4] = 183456903;
	dp[32][5] = 852780547;
	dp[32][6] = 352902464;
	dp[32][7] = 760172918;
	dp[32][8] = 140264954;
	dp[32][9] = 368317456;
	dp[32][10] = 111888578;
	dp[32][11] = 886633383;
	dp[32][12] = 579726165;
	dp[32][13] = 104629126;
	dp[32][14] = 551328575;
	dp[32][15] = 899899836;
	dp[32][16] = 446523616;
	dp[32][17] = 758809033;
	dp[32][18] = 623506340;
	dp[32][19] = 276900789;
	dp[32][20] = 639466287;
	dp[32][21] = 84062703;
	dp[32][22] = 74828396;
	dp[32][23] = 434685925;
	dp[32][24] = 25258990;
	dp[32][25] = 721888398;
	dp[32][26] = 281541412;
	dp[32][27] = 136479360;
	dp[32][28] = 4080096;
	dp[32][29] = 113152;
	dp[32][30] = 2849;
	dp[32][31] = 62;
	dp[32][32] = 1;
	dp[33][1] = 1;
	dp[33][2] = 433084024;
	dp[33][3] = 341549021;
	dp[33][4] = 10185087;
	dp[33][5] = 548383746;
	dp[33][6] = 11073302;
	dp[33][7] = 625126048;
	dp[33][8] = 289059971;
	dp[33][9] = 717814913;
	dp[33][10] = 38262713;
	dp[33][11] = 861814428;
	dp[33][12] = 699457116;
	dp[33][13] = 820395829;
	dp[33][14] = 84444712;
	dp[33][15] = 846174190;
	dp[33][16] = 262420024;
	dp[33][17] = 552986946;
	dp[33][18] = 93527201;
	dp[33][19] = 581833374;
	dp[33][20] = 755311411;
	dp[33][21] = 90038673;
	dp[33][22] = 190103917;
	dp[33][23] = 195102162;
	dp[33][24] = 975486471;
	dp[33][25] = 366688387;
	dp[33][26] = 255570713;
	dp[33][27] = 245289245;
	dp[33][28] = 161192064;
	dp[33][29] = 4651680;
	dp[33][30] = 124674;
	dp[33][31] = 3037;
	dp[33][32] = 64;
	dp[33][33] = 1;
	dp[34][1] = 1;
	dp[34][2] = 125050652;
	dp[34][3] = 141775748;
	dp[34][4] = 2195775;
	dp[34][5] = 861688483;
	dp[34][6] = 467846739;
	dp[34][7] = 643806518;
	dp[34][8] = 866825417;
	dp[34][9] = 671006440;
	dp[34][10] = 382607258;
	dp[34][11] = 77746847;
	dp[34][12] = 952548276;
	dp[34][13] = 414170722;
	dp[34][14] = 706077925;
	dp[34][15] = 512030434;
	dp[34][16] = 775485932;
	dp[34][17] = 885776802;
	dp[34][18] = 785741046;
	dp[34][19] = 881986078;
	dp[34][20] = 880006603;
	dp[34][21] = 804277621;
	dp[34][22] = 969606548;
	dp[34][23] = 549342491;
	dp[34][24] = 992492989;
	dp[34][25] = 976033262;
	dp[34][26] = 489346313;
	dp[34][27] = 549827699;
	dp[34][28] = 383192598;
	dp[34][29] = 189357696;
	dp[34][30] = 5281254;
	dp[34][31] = 136952;
	dp[34][32] = 3231;
	dp[34][33] = 66;
	dp[34][34] = 1;
	dp[35][1] = 1;
	dp[35][2] = 30668696;
	dp[35][3] = 556671762;
	dp[35][4] = 791281983;
	dp[35][5] = 685748611;
	dp[35][6] = 762217922;
	dp[35][7] = 264182766;
	dp[35][8] = 615522170;
	dp[35][9] = 899368504;
	dp[35][10] = 520305089;
	dp[35][11] = 246374466;
	dp[35][12] = 802021834;
	dp[35][13] = 460585739;
	dp[35][14] = 343550574;
	dp[35][15] = 987670393;
	dp[35][16] = 493685546;
	dp[35][17] = 348832682;
	dp[35][18] = 704504429;
	dp[35][19] = 357314817;
	dp[35][20] = 779888986;
	dp[35][21] = 153412957;
	dp[35][22] = 648798243;
	dp[35][23] = 282402948;
	dp[35][24] = 645616384;
	dp[35][25] = 963150393;
	dp[35][26] = 125095330;
	dp[35][27] = 593739158;
	dp[35][28] = 4926855;
	dp[35][29] = 719539471;
	dp[35][30] = 221325720;
	dp[35][31] = 5972610;
	dp[35][32] = 150010;
	dp[35][33] = 3431;
	dp[35][34] = 68;
	dp[35][35] = 1;
	dp[36][1] = 1;
	dp[36][2] = 250950620;
	dp[36][3] = 772806284;
	dp[36][4] = 808641658;
	dp[36][5] = 311734930;
	dp[36][6] = 298298828;
	dp[36][7] = 925751461;
	dp[36][8] = 73825809;
	dp[36][9] = 578907118;
	dp[36][10] = 650453099;
	dp[36][11] = 999898518;
	dp[36][12] = 964011780;
	dp[36][13] = 935009609;
	dp[36][14] = 740360677;
	dp[36][15] = 295420577;
	dp[36][16] = 130120821;
	dp[36][17] = 398242118;
	dp[36][18] = 615472272;
	dp[36][19] = 424216146;
	dp[36][20] = 343694583;
	dp[36][21] = 655937465;
	dp[36][22] = 9231241;
	dp[36][23] = 161478300;
	dp[36][24] = 943221943;
	dp[36][25] = 544926303;
	dp[36][26] = 430513636;
	dp[36][27] = 966323193;
	dp[36][28] = 532063461;
	dp[36][29] = 216146261;
	dp[36][30] = 281071737;
	dp[36][31] = 257468400;
	dp[36][32] = 6729660;
	dp[36][33] = 163872;
	dp[36][34] = 3637;
	dp[36][35] = 70;
	dp[36][36] = 1;
	dp[37][1] = 1;
	dp[37][2] = 914756502;
	dp[37][3] = 700333728;
	dp[37][4] = 979699168;
	dp[37][5] = 950314645;
	dp[37][6] = 95181677;
	dp[37][7] = 300996143;
	dp[37][8] = 379686046;
	dp[37][9] = 515581803;
	dp[37][10] = 129090705;
	dp[37][11] = 704160285;
	dp[37][12] = 322942639;
	dp[37][13] = 924390198;
	dp[37][14] = 704583561;
	dp[37][15] = 919487007;
	dp[37][16] = 829879797;
	dp[37][17] = 838443941;
	dp[37][18] = 710314757;
	dp[37][19] = 448661675;
	dp[37][20] = 621276888;
	dp[37][21] = 193314778;
	dp[37][22] = 483858206;
	dp[37][23] = 788670019;
	dp[37][24] = 837405831;
	dp[37][25] = 408231647;
	dp[37][26] = 231030449;
	dp[37][27] = 647362866;
	dp[37][28] = 810125030;
	dp[37][29] = 568254543;
	dp[37][30] = 993451423;
	dp[37][31] = 97145003;
	dp[37][32] = 298181520;
	dp[37][33] = 7556436;
	dp[37][34] = 178562;
	dp[37][35] = 3849;
	dp[37][36] = 72;
	dp[37][37] = 1;
	dp[38][1] = 1;
	dp[38][2] = 300292876;
	dp[38][3] = 848791474;
	dp[38][4] = 513128681;
	dp[38][5] = 761922660;
	dp[38][6] = 80488690;
	dp[38][7] = 904691803;
	dp[38][8] = 437319689;
	dp[38][9] = 107720922;
	dp[38][10] = 739046371;
	dp[38][11] = 529350567;
	dp[38][12] = 934806933;
	dp[38][13] = 517580716;
	dp[38][14] = 636943530;
	dp[38][15] = 661795150;
	dp[38][16] = 144098478;
	dp[38][17] = 657538675;
	dp[38][18] = 109785295;
	dp[38][19] = 305126411;
	dp[38][20] = 982462849;
	dp[38][21] = 443853694;
	dp[38][22] = 794098649;
	dp[38][23] = 900432820;
	dp[38][24] = 472800139;
	dp[38][25] = 859228306;
	dp[38][26] = 256146024;
	dp[38][27] = 549177628;
	dp[38][28] = 488280923;
	dp[38][29] = 285704129;
	dp[38][30] = 315448166;
	dp[38][31] = 382452313;
	dp[38][32] = 199893469;
	dp[38][33] = 343885104;
	dp[38][34] = 8457090;
	dp[38][35] = 194104;
	dp[38][36] = 4067;
	dp[38][37] = 74;
	dp[38][38] = 1;
	dp[39][1] = 1;
	dp[39][2] = 618779736;
	dp[39][3] = 646679894;
	dp[39][4] = 871340262;
	dp[39][5] = 820691930;
	dp[39][6] = 265855599;
	dp[39][7] = 373488820;
	dp[39][8] = 549393857;
	dp[39][9] = 835324402;
	dp[39][10] = 470797364;
	dp[39][11] = 935220670;
	dp[39][12] = 20425067;
	dp[39][13] = 271361769;
	dp[39][14] = 880980656;
	dp[39][15] = 482633330;
	dp[39][16] = 259018944;
	dp[39][17] = 418434399;
	dp[39][18] = 745290706;
	dp[39][19] = 264511501;
	dp[39][20] = 899760121;
	dp[39][21] = 128088900;
	dp[39][22] = 861837922;
	dp[39][23] = 424799495;
	dp[39][24] = 842977735;
	dp[39][25] = 20510780;
	dp[39][26] = 592266715;
	dp[39][27] = 444093991;
	dp[39][28] = 480625675;
	dp[39][29] = 131695076;
	dp[39][30] = 309958198;
	dp[39][31] = 862386773;
	dp[39][32] = 686680931;
	dp[39][33] = 624399855;
	dp[39][34] = 395024136;
	dp[39][35] = 9435894;
	dp[39][36] = 210522;
	dp[39][37] = 4291;
	dp[39][38] = 76;
	dp[39][39] = 1;
	dp[40][1] = 1;
	dp[40][2] = 998223525;
	dp[40][3] = 658969162;
	dp[40][4] = 271826144;
	dp[40][5] = 57374202;
	dp[40][6] = 428143481;
	dp[40][7] = 92616119;
	dp[40][8] = 227792871;
	dp[40][9] = 668252416;
	dp[40][10] = 757079874;
	dp[40][11] = 1555604;
	dp[40][12] = 908913207;
	dp[40][13] = 464299446;
	dp[40][14] = 535182156;
	dp[40][15] = 904112291;
	dp[40][16] = 975422543;
	dp[40][17] = 887624635;
	dp[40][18] = 944735120;
	dp[40][19] = 413694279;
	dp[40][20] = 492247614;
	dp[40][21] = 835354141;
	dp[40][22] = 153149510;
	dp[40][23] = 308769997;
	dp[40][24] = 870006657;
	dp[40][25] = 244714413;
	dp[40][26] = 793542231;
	dp[40][27] = 810425354;
	dp[40][28] = 731819188;
	dp[40][29] = 837167892;
	dp[40][30] = 697520156;
	dp[40][31] = 365337256;
	dp[40][32] = 100664639;
	dp[40][33] = 491229569;
	dp[40][34] = 408870354;
	dp[40][35] = 452069280;
	dp[40][36] = 10497240;
	dp[40][37] = 227840;
	dp[40][38] = 4521;
	dp[40][39] = 78;
	dp[40][40] = 1;
	dp[41][1] = 1;
	dp[41][2] = 672435685;
	dp[41][3] = 655948135;
	dp[41][4] = 559263759;
	dp[41][5] = 266147010;
	dp[41][6] = 961873090;
	dp[41][7] = 263480382;
	dp[41][8] = 587824794;
	dp[41][9] = 404313513;
	dp[41][10] = 391472772;
	dp[41][11] = 254397283;
	dp[41][12] = 569515842;
	dp[41][13] = 815980212;
	dp[41][14] = 310501178;
	dp[41][15] = 67341738;
	dp[41][16] = 142364755;
	dp[41][17] = 653959283;
	dp[41][18] = 239590143;
	dp[41][19] = 115060470;
	dp[41][20] = 307944570;
	dp[41][21] = 433244556;
	dp[41][22] = 144077547;
	dp[41][23] = 647972658;
	dp[41][24] = 857069658;
	dp[41][25] = 428902764;
	dp[41][26] = 753056691;
	dp[41][27] = 140738422;
	dp[41][28] = 783071519;
	dp[41][29] = 667843540;
	dp[41][30] = 865211236;
	dp[41][31] = 643356967;
	dp[41][32] = 97781384;
	dp[41][33] = 265069346;
	dp[41][34] = 687790293;
	dp[41][35] = 594814653;
	dp[41][36] = 515517600;
	dp[41][37] = 11645640;
	dp[41][38] = 246082;
	dp[41][39] = 4757;
	dp[41][40] = 80;
	dp[41][41] = 1;
	dp[42][1] = 1;
	dp[42][2] = 142639726;
	dp[42][3] = 62367073;
	dp[42][4] = 297889618;
	dp[42][5] = 795526546;
	dp[42][6] = 373334514;
	dp[42][7] = 535344206;
	dp[42][8] = 844642444;
	dp[42][9] = 48000903;
	dp[42][10] = 321917643;
	dp[42][11] = 658248125;
	dp[42][12] = 653127430;
	dp[42][13] = 877455854;
	dp[42][14] = 665572146;
	dp[42][15] = 624534015;
	dp[42][16] = 129874972;
	dp[42][17] = 691238142;
	dp[42][18] = 310231983;
	dp[42][19] = 162920739;
	dp[42][20] = 326560120;
	dp[42][21] = 654851050;
	dp[42][22] = 379059492;
	dp[42][23] = 727771784;
	dp[42][24] = 842397907;
	dp[42][25] = 629615692;
	dp[42][26] = 777049390;
	dp[42][27] = 269577548;
	dp[42][28] = 585374225;
	dp[42][29] = 495757038;
	dp[42][30] = 548043095;
	dp[42][31] = 931234428;
	dp[42][32] = 869129060;
	dp[42][33] = 368513014;
	dp[42][34] = 699639553;
	dp[42][35] = 501135795;
	dp[42][36] = 227230945;
	dp[42][37] = 585893280;
	dp[42][38] = 12885726;
	dp[42][39] = 265272;
	dp[42][40] = 4999;
	dp[42][41] = 82;
	dp[42][42] = 1;
	dp[43][1] = 1;
	dp[43][2] = 428619828;
	dp[43][3] = 685003174;
	dp[43][4] = 145463329;
	dp[43][5] = 476536865;
	dp[43][6] = 726259495;
	dp[43][7] = 377103284;
	dp[43][8] = 913437753;
	dp[43][9] = 636096066;
	dp[43][10] = 854785621;
	dp[43][11] = 344906347;
	dp[43][12] = 831694306;
	dp[43][13] = 261660425;
	dp[43][14] = 179461058;
	dp[43][15] = 605584210;
	dp[43][16] = 558747479;
	dp[43][17] = 71612337;
	dp[43][18] = 776745688;
	dp[43][19] = 25521495;
	dp[43][20] = 550208762;
	dp[43][21] = 888037339;
	dp[43][22] = 395068026;
	dp[43][23] = 349760832;
	dp[43][24] = 578427986;
	dp[43][25] = 548562775;
	dp[43][26] = 805872652;
	dp[43][27] = 10080613;
	dp[43][28] = 115029584;
	dp[43][29] = 509680176;
	dp[43][30] = 560224566;
	dp[43][31] = 183485980;
	dp[43][32] = 151920370;
	dp[43][33] = 976883464;
	dp[43][34] = 19740674;
	dp[43][35] = 862422276;
	dp[43][36] = 517082054;
	dp[43][37] = 354796037;
	dp[43][38] = 663748344;
	dp[43][39] = 14222250;
	dp[43][40] = 285434;
	dp[43][41] = 5247;
	dp[43][42] = 84;
	dp[43][43] = 1;
	dp[44][1] = 1;
	dp[44][2] = 147785237;
	dp[44][3] = 750334107;
	dp[44][4] = 499627544;
	dp[44][5] = 204229320;
	dp[44][6] = 356989310;
	dp[44][7] = 16912187;
	dp[44][8] = 789212750;
	dp[44][9] = 816120416;
	dp[44][10] = 741113672;
	dp[44][11] = 313988556;
	dp[44][12] = 80276815;
	dp[44][13] = 785846123;
	dp[44][14] = 239914289;
	dp[44][15] = 325901810;
	dp[44][16] = 457142933;
	dp[44][17] = 205262440;
	dp[44][18] = 444697000;
	dp[44][19] = 795853309;
	dp[44][20] = 678416069;
	dp[44][21] = 631551186;
	dp[44][22] = 486483214;
	dp[44][23] = 834747317;
	dp[44][24] = 84833525;
	dp[44][25] = 40642937;
	dp[44][26] = 739357296;
	dp[44][27] = 846376698;
	dp[44][28] = 594577378;
	dp[44][29] = 879545850;
	dp[44][30] = 402232984;
	dp[44][31] = 251240686;
	dp[44][32] = 976822464;
	dp[44][33] = 739126628;
	dp[44][34] = 19154290;
	dp[44][35] = 744242259;
	dp[44][36] = 582275507;
	dp[44][37] = 711973042;
	dp[44][38] = 30060442;
	dp[44][39] = 749663376;
	dp[44][40] = 15660084;
	dp[44][41] = 306592;
	dp[44][42] = 5501;
	dp[44][43] = 86;
	dp[44][44] = 1;
	dp[45][1] = 1;
	dp[45][2] = 227467156;
	dp[45][3] = 554228530;
	dp[45][4] = 578757564;
	dp[45][5] = 124344998;
	dp[45][6] = 415295563;
	dp[45][7] = 211094890;
	dp[45][8] = 393475094;
	dp[45][9] = 677495859;
	dp[45][10] = 964422522;
	dp[45][11] = 658603674;
	dp[45][12] = 702708966;
	dp[45][13] = 854346330;
	dp[45][14] = 451741206;
	dp[45][15] = 827156183;
	dp[45][16] = 309332175;
	dp[45][17] = 348148322;
	dp[45][18] = 315587887;
	dp[45][19] = 914138093;
	dp[45][20] = 674567453;
	dp[45][21] = 904989586;
	dp[45][22] = 526768309;
	dp[45][23] = 600815496;
	dp[45][24] = 347612936;
	dp[45][25] = 503577411;
	dp[45][26] = 914316390;
	dp[45][27] = 214288688;
	dp[45][28] = 753388925;
	dp[45][29] = 992384537;
	dp[45][30] = 956335398;
	dp[45][31] = 309423727;
	dp[45][32] = 111690651;
	dp[45][33] = 292150876;
	dp[45][34] = 637351846;
	dp[45][35] = 385708317;
	dp[45][36] = 582335514;
	dp[45][37] = 581424993;
	dp[45][38] = 483727844;
	dp[45][39] = 309648567;
	dp[45][40] = 844248240;
	dp[45][41] = 17204220;
	dp[45][42] = 328770;
	dp[45][43] = 5761;
	dp[45][44] = 88;
	dp[45][45] = 1;
	dp[46][1] = 1;
	dp[46][2] = 620227420;
	dp[46][3] = 150760474;
	dp[46][4] = 291030614;
	dp[46][5] = 379410304;
	dp[46][6] = 175356279;
	dp[46][7] = 79179875;
	dp[46][8] = 419048343;
	dp[46][9] = 818350099;
	dp[46][10] = 262987135;
	dp[46][11] = 507001357;
	dp[46][12] = 753810764;
	dp[46][13] = 935528753;
	dp[46][14] = 108579781;
	dp[46][15] = 124854991;
	dp[46][16] = 550276882;
	dp[46][17] = 816332931;
	dp[46][18] = 979545257;
	dp[46][19] = 399789988;
	dp[46][20] = 140241033;
	dp[46][21] = 826664256;
	dp[46][22] = 428844589;
	dp[46][23] = 917421192;
	dp[46][24] = 374994370;
	dp[46][25] = 198242488;
	dp[46][26] = 647515289;
	dp[46][27] = 714806567;
	dp[46][28] = 536616774;
	dp[46][29] = 639480014;
	dp[46][30] = 360584951;
	dp[46][31] = 398766308;
	dp[46][32] = 253053496;
	dp[46][33] = 885771160;
	dp[46][34] = 986989406;
	dp[46][35] = 903699576;
	dp[46][36] = 264575862;
	dp[46][37] = 706912363;
	dp[46][38] = 277846834;
	dp[46][39] = 684490512;
	dp[46][40] = 254463885;
	dp[46][41] = 948142800;
	dp[46][42] = 18859770;
	dp[46][43] = 351992;
	dp[46][44] = 6027;
	dp[46][45] = 90;
	dp[46][46] = 1;
	dp[47][1] = 1;
	dp[47][2] = 277405898;
	dp[47][3] = 548325526;
	dp[47][4] = 265706766;
	dp[47][5] = 725634397;
	dp[47][6] = 265720096;
	dp[47][7] = 821959326;
	dp[47][8] = 146581784;
	dp[47][9] = 878883168;
	dp[47][10] = 457088943;
	dp[47][11] = 346662600;
	dp[47][12] = 8455639;
	dp[47][13] = 700892835;
	dp[47][14] = 489465769;
	dp[47][15] = 173083027;
	dp[47][16] = 696207060;
	dp[47][17] = 995589597;
	dp[47][18] = 783686670;
	dp[47][19] = 838648835;
	dp[47][20] = 628406976;
	dp[47][21] = 411701410;
	dp[47][22] = 195959801;
	dp[47][23] = 636467154;
	dp[47][24] = 710308167;
	dp[47][25] = 900438787;
	dp[47][26] = 114415398;
	dp[47][27] = 899676621;
	dp[47][28] = 615131959;
	dp[47][29] = 575766924;
	dp[47][30] = 297869156;
	dp[47][31] = 509939602;
	dp[47][32] = 311842688;
	dp[47][33] = 632298971;
	dp[47][34] = 822322114;
	dp[47][35] = 46384033;
	dp[47][36] = 860758405;
	dp[47][37] = 408935593;
	dp[47][38] = 298010808;
	dp[47][39] = 881910516;
	dp[47][40] = 654922924;
	dp[47][41] = 929899203;
	dp[47][42] = 62017633;
	dp[47][43] = 20631966;
	dp[47][44] = 376282;
	dp[47][45] = 6299;
	dp[47][46] = 92;
	dp[47][47] = 1;
	dp[48][1] = 1;
	dp[48][2] = 843582718;
	dp[48][3] = 916600057;
	dp[48][4] = 256042379;
	dp[48][5] = 683180552;
	dp[48][6] = 836275500;
	dp[48][7] = 723343395;
	dp[48][8] = 174362340;
	dp[48][9] = 904336274;
	dp[48][10] = 16032412;
	dp[48][11] = 193918791;
	dp[48][12] = 576781189;
	dp[48][13] = 329765947;
	dp[48][14] = 560577157;
	dp[48][15] = 496138403;
	dp[48][16] = 134574899;
	dp[48][17] = 863673603;
	dp[48][18] = 736958785;
	dp[48][19] = 580886664;
	dp[48][20] = 250811713;
	dp[48][21] = 619976508;
	dp[48][22] = 309162555;
	dp[48][23] = 773162039;
	dp[48][24] = 598833395;
	dp[48][25] = 207073151;
	dp[48][26] = 189396374;
	dp[48][27] = 765351153;
	dp[48][28] = 445233984;
	dp[48][29] = 606722836;
	dp[48][30] = 115795015;
	dp[48][31] = 337416901;
	dp[48][32] = 48214859;
	dp[48][33] = 400977822;
	dp[48][34] = 294838044;
	dp[48][35] = 706637957;
	dp[48][36] = 749665813;
	dp[48][37] = 463536892;
	dp[48][38] = 786584257;
	dp[48][39] = 452824684;
	dp[48][40] = 802079728;
	dp[48][41] = 260181038;
	dp[48][42] = 406051907;
	dp[48][43] = 186574777;
	dp[48][44] = 22526160;
	dp[48][45] = 401664;
	dp[48][46] = 6577;
	dp[48][47] = 94;
	dp[48][48] = 1;
	dp[49][1] = 1;
	dp[49][2] = 374681281;
	dp[49][3] = 74298326;
	dp[49][4] = 443396644;
	dp[49][5] = 254363038;
	dp[49][6] = 158756274;
	dp[49][7] = 441903650;
	dp[49][8] = 776473475;
	dp[49][9] = 975787907;
	dp[49][10] = 722710278;
	dp[49][11] = 142151858;
	dp[49][12] = 146613332;
	dp[49][13] = 431546410;
	dp[49][14] = 46926463;
	dp[49][15] = 949966642;
	dp[49][16] = 821506685;
	dp[49][17] = 786764279;
	dp[49][18] = 489967656;
	dp[49][19] = 268324786;
	dp[49][20] = 634373372;
	dp[49][21] = 944293004;
	dp[49][22] = 950463669;
	dp[49][23] = 544597466;
	dp[49][24] = 77017115;
	dp[49][25] = 461156460;
	dp[49][26] = 455830313;
	dp[49][27] = 965014696;
	dp[49][28] = 842572692;
	dp[49][29] = 255041745;
	dp[49][30] = 759661388;
	dp[49][31] = 688920563;
	dp[49][32] = 271059109;
	dp[49][33] = 128656900;
	dp[49][34] = 792529526;
	dp[49][35] = 155274450;
	dp[49][36] = 963494778;
	dp[49][37] = 610107099;
	dp[49][38] = 163841138;
	dp[49][39] = 123299610;
	dp[49][40] = 225106330;
	dp[49][41] = 374831402;
	dp[49][42] = 927614819;
	dp[49][43] = 757944331;
	dp[49][44] = 322548409;
	dp[49][45] = 24547824;
	dp[49][46] = 428162;
	dp[49][47] = 6861;
	dp[49][48] = 96;
	dp[49][49] = 1;
	dp[50][1] = 1;
	dp[50][2] = 521201982;
	dp[50][3] = 768687718;
	dp[50][4] = 867527430;
	dp[50][5] = 454013282;
	dp[50][6] = 259258318;
	dp[50][7] = 449657493;
	dp[50][8] = 542374813;
	dp[50][9] = 339516913;
	dp[50][10] = 91973450;
	dp[50][11] = 67617505;
	dp[50][12] = 360753370;
	dp[50][13] = 249784912;
	dp[50][14] = 435926003;
	dp[50][15] = 33383401;
	dp[50][16] = 967542950;
	dp[50][17] = 349491043;
	dp[50][18] = 399862924;
	dp[50][19] = 834072735;
	dp[50][20] = 349787786;
	dp[50][21] = 902124800;
	dp[50][22] = 97222295;
	dp[50][23] = 91011746;
	dp[50][24] = 366999255;
	dp[50][25] = 180876403;
	dp[50][26] = 561917933;
	dp[50][27] = 391157203;
	dp[50][28] = 434015449;
	dp[50][29] = 33236527;
	dp[50][30] = 268353506;
	dp[50][31] = 220654156;
	dp[50][32] = 979506994;
	dp[50][33] = 470032890;
	dp[50][34] = 899749308;
	dp[50][35] = 264462362;
	dp[50][36] = 668248137;
	dp[50][37] = 345332025;
	dp[50][38] = 252697527;
	dp[50][39] = 909492886;
	dp[50][40] = 415313001;
	dp[50][41] = 39601300;
	dp[50][42] = 934316071;
	dp[50][43] = 686232124;
	dp[50][44] = 65749061;
	dp[50][45] = 470705593;
	dp[50][46] = 26702550;
	dp[50][47] = 455800;
	dp[50][48] = 7151;
	dp[50][49] = 98;
	dp[50][50] = 1;
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		printf("Case %d: %d\n", icase++, dp[n][k]);
	}
	return 0;
}
