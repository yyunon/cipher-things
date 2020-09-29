#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <chrono>


static constexpr char a_table[26][27] = { "abcdefghijklmnopqrstuvwxyz",
					  "bcdefghijklmnopqrstuvwxyza",
					  "cdefghijklmnopqrstuvwxyzab",
					  "defghijklmnopqrstuvwxyzabc",
					  "efghijklmnopqrstuvwxyzabcd",
					  "fghijklmnopqrstuvwxyzabcde",
					  "ghijklmnopqrstuvwxyzabcdef",
					  "hijklmnopqrstuvwxyzabcdefg",
					  "ijklmnopqrstuvwxyzabcdefgh",
					  "jklmnopqrstuvwxyzabcdefghi",
					  "klmnopqrstuvwxyzabcdefghij",
					  "lmnopqrstuvwxyzabcdefghijk",
					  "mnopqrstuvwxyzabcdefghijkl",
					  "nopqrstuvwxyzabcdefghijklm",
					  "opqrstuvwxyzabcdefghijklmn",
					  "pqrstuvwxyzabcdefghijklmno",
					  "qrstuvwxyzabcdefghijklmnop",
					  "rstuvwxyzabcdefghijklmnopq",
					  "stuvwxyzabcdefghijklmnopqr",
					  "tuvwxyzabcdefghijklmnopqrs",
					  "uvwxyzabcdefghijklmnopqrst",
					  "vwxyzabcdefghijklmnopqrstu",
					  "wxyzabcdefghijklmnopqrstuv",
					  "xyzabcdefghijklmnopqrstuvw",
					  "yzabcdefghijklmnopqrstuvwx",
					  "zabcdefghijklmnopqrstuvwxy"};

static constexpr char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

static constexpr char text1[] = "lww esp hzcwod l delrp lyo lww esp xpy lyo hzxpy xpcpwj awljpcd espj slgp esptc pited lyo esptc pyeclynpd lyo zyp xly ty std etxp awljd xlyj alced\0";
static constexpr char text2[] = "gv srbxmghp mteyljviikw hm Whtbilwiakvw iseyl rvx rrope xh lbilk xhkey bk ml hgtnrpef xhteol as a zisnw sf ttxhyw fkfq Loekxjtxhvel tsfwenr klta ae arzx hfonk ltsj oy klx wparj em hpl myir jslevgmlh tavq yvv pnspbjetbfr tmxek jltrisivekl hixu tklwekmmgn xhx gptfw tavwx dvimzrzz aekv fkvygak xhnitavv bu ahtk ml rrope el ale yzvla joezs loekxjtxhvel cizhgy bj el ymca rrw kmvxiwx hw hbj ahyo hbj tehcs arzx ztapeiw jsugkpxzw awrtmhxihew tjvolj qnsxiici zlrrxj egk guekyklw hbj tehcs arzx oed te igkyrbek iyisxegx vr smrkx hrd yzpf oms pimmprgl yeol fexe ghttievh bu zakzsnz mtxiempsnl fj moi chdtelxe pfvdz sf pzpepem Lyedlwpxrvx dlivy mgjpuwv ees sf azw iseyl jsguitl rrw vxhxi thlqs pzpepem lyedlwpxrvx jsnmzrnlw th si hui oy klx tssm zqivvttex epxekrvr mmgniil vj tav ignpily ptukutxi\0";

static constexpr char n_text2[] = "gvsrbxmghpmteyljviikwhmwhtbilwiakvwiseylrvxrropexhlbilkxhkeybkmlhgtnrpefxhteolasazisnwsfttxhywfkfqloekxjtxhveltsfwenrkltaaearzxhfonkltsjoyklxwparjemhplmyirjslevgmlhtavqyvvpnspbjetbfrtmxekjltrisiveklhixutklwekmmgnxhxgptfwtavwxdvimzrzzaekvfkvygakxhnitavvbuahtkmlrropeelaleyzvlajoezsloekxjtxhvelcizhgybjelymcarrwkmvxiwxhwhbjahyohbjtehcsarzxztapeiwjsugkpxzwawrtmhxihewtjvoljqnsxiicizlrrxjegkguekyklwhbjtehcsarzxoedteigkyrbekiyisxegxvrsmrkxhrdyzpfomspimmprglyeolfexeghttievhbuzakzsnzmtxiempsnlfjmoichdtelxepfvdzsfpzpepemlyedlwpxrvxdlivymgjpuwveessfazwiseyljsguitlrrwvxhxithlqspzpepemlyedlwpxrvxjsnmzrnlwthsihuioyklxtssmzqivvttexepxekrvrmmgniilvjtavignpilyptukutxi\0";
static constexpr char n_text1[] = "lwwesphzcwodldelrplyolwwespxpylyohzxpyxpcpwjawljpcdespjslgpesptcpitedlyoesptcpyeclynpdlyozypxlytystdetxpawljdxlyjalced\0";

//Test samples from book for algorithms
static constexpr char test_vigenere[]= "utpdhug nyh usvkcg mvce fxl kqib wx rku gi tzn rls bbhzlxmsnp kdks ceb ih hkew iba yym sbr pfr sbs jv upl o uvadgr hrrwxf jv ztvoov yh zcqu y ukwgeb pl uqfb p foukcg tbf rq vhcf r kpg ou kft zcqu maw qkkw zgsy fp pgm qkftk uqfb der ezrn mcye mg uctfsva wp kft zcqu maw kqijs lcov nthdnv jpnujvb ih ggv rwx onkcgthkfl xg vkd zjm vg cci mvgd jpnuj rls ewvkjt asgucs mvgd ddk vg nyh pwuv cchiiy rd dbqn rwth pfrwbbi vttk vcgntgsf fl iawu xjdus hfp vhcf rr lawey qdfs rvmees fzb chh jrtt mvgzp ubzn fd atiiyrtk wp kft hivjci tbf bldpwpx rwth ulaw tg vychx kqljs us dcgcw oppupr vg kfdnujk gi jikkc pl kgcj iaov kftr gjfsaw ktzlzes wg rwxwt vwtl wp xpxgg cj fpos vyc btzcuw xg zgjq pmhtraibjg wmgfg jzq dpb jvygm zclewxr ceb iaov nyh jikkc tgcwxf uhf jzk wx vcu ld yitkftk wpkcgvcwiqt pwvy qebfkkq qnh nzttw irfl ias vfrpe odjrxgsptc ekwptgees gmcg ttvvpltffj ycw wv nyh tzyrwh loku mu awo kfpm vg bltp vqn rd dsgg awkwukkpl kgcj xy opp kpg onztt icujchlsf kft dbqnjtwug dyn mvck zt mfwcw htwf fd jl opu yae ch lq pgr uf yh mwpp rxf cdjcgosf xms uzgjq jl sxvpn hbg";
static constexpr char n_test_vigenere[]= "utpdhugnyhusvkcgmvcefxlkqibwxrkugitznrlsbbhzlxmsnpkdkscebihhkewibayymsbrpfrsbsjvuplouvadgrhrrwxfjvztvoovyhzcquyukwgebpluqfbpfoukcgtbfrqvhcfrkpgoukftzcqumawqkkwzgsyfppgmqkftkuqfbderezrnmcyemguctfsvawpkftzcqumawkqijslcovnthdnvjpnujvbihggvrwxonkcgthkflxgvkdzjmvgccimvgdjpnujrlsewvkjtasgucsmvgdddkvgnyhpwuvcchiiyrddbqnrwthpfrwbbivttkvcgntgsffliawuxjdushfpvhcfrrlaweyqdfsrvmeesfzbchhjrttmvgzpubznfdatiiyrtkwpkfthivjcitbfbldpwpxrwthulawtgvychxkqljsusdcgcwoppuprvgkfdnujkgijikkcplkgcjiaovkftrgjfsawktzlzeswgrwxwtvwtlwpxpxggcjfposvycbtzcuwxgzgjqpmhtraibjgwmgfgjzqdpbjvygmzclewxrcebiaovnyhjikkctgcwxfuhfjzkwxvculdyitkftkwpkcgvcwiqtpwvyqebfkkqqnhnzttwirfliasvfrpeodjrxgsptcekwptgeesgmcgttvvpltffjycwwvnyhtzyrwhlokumuawokfpmvgbltpvqnrddsggawkwukkplkgcjxyoppkpgonztticujchlsfkftdbqnjtwugdynmvckztmfwcwhtwffdjlopuyaechlqpgrufyhmwpprxfcdjcgosfxmsuzgjqjlsxvpnhbg";
static constexpr char test_shift[]= "gb or be abg gb or gung vf gur dhrfgvba jurgure gvf aboyre va gur zvaq gb fhssre gur fyvatf naq neebjf bs bhgentrbhf sbeghar be gb gnxr nezf ntnvafg n frn bs gebhoyrf naq ol bccbfvat raq gurz gb qvr gb fyrrc ab zber naq ol n fyrrc gb fnl jr raq gur urneg npur naq gur gubhfnaq angheny fubpxf gung syrfu vf urve gb gvf n pbafhzzngvba qribhgyl gb or jvfuq gb qvr gb fyrrc gb fyrrc crepunapr gb qernz nl gurerf gur eho sbe va gung fyrrc bs qrngu jung qernzf znl pbzr jura jr unir fuhssyrq bss guvf zbegny pbvy zhfg tvir hf cnhfr gurerf gur erfcrpg gung znxrf pnynzvgl bs fb ybat yvsr\0";
static constexpr char test_sub[]= "gb or be abg gb or gung vf gur dhrfgvba jurgure gvf aboyre va gur zvaq gb fhssre gur fyvatf naq neebjf bs bhgentrbhf sbeghar be gb gnxr nezf ntnvafg n frn bs gebhoyrf naq ol bccbfvat raq gurz gb qvr gb fyrrc ab zber naq ol n fyrrc gb fnl jr raq gur urneg npur naq gur gubhfnaq angheny fubpxf gung syrfu vf urve gb gvf n pbafhzzngvba qribhgyl gb or jvfuq gb qvr gb fyrrc gb fyrrc crepunapr gb qernz nl gurerf gur eho sbe va gung fyrrc bs qrngu jung qernzf znl pbzr jura jr unir fuhssyrq bss guvf zbegny pbvy zhfg tvir hf cnhfr gurerf gur erfcrpg gung znxrf pnynzvgl bs fb ybat yvsr\0";
static constexpr char n_test_sub[]= "xsomjiwxvljodivastwvaovyozjvcowltjdowxkvakoaxjtxivawvysidsxoksavlvdqiagzwxjqkvuczxojwkvuuzaiktxivawtaguikjvolokxjvaikwtjoholljocjowoaxogtlvadwigogidixtluogitkvuczxojdtuowtagolokxjvaikkvuuojkotwholltwsvwxiadutaqjowotjkstagcjvgzkxgonolvcuoaxkoaxjowvyutpvjdlvmtlkvuctaiowxsojodivastwtjtciglqdjvhiadazumojvyiaavntxinoaohkvuctaiowxsokvuczxojwkioakogoctjxuoaxstwklvwojoltxivawsicwhixsutaqvyxsowovjdtaiwtxivawnitkvlltmvjtxinocjvpokxwwxtyywokvaguoaxwtagniwixiadiagzwxjitlwxtyyixstwjokoaxlqiaxjvgzkogwonojtluokstaiwuwyvjgonolvciadtagwzccvjxiadoaxjocjoaozjitlwxzgoaxwtagwxtyytagtiuwxvcltqtwidaiyiktaxjvloiaxsogonolvcuoaxvysidsxoksavlvdqiagzwxjqiaxsojodivaxsogoctjxuoaxstwtltjdocjvdjtuuovyjowotjkswzccvjxogmqiagzwxjqxsoozjvcotazaivatagzedvnojauoaxjowotjksowxtmliwsuoaxwtagczmlikkvjcvjtxivawteoqolouoaxvyxsiwiwxsowxjvadliaewxstxxsogoctjxuoaxstwhixsxsokvuczxojkvuuzaiktxivawuikjvolokxjvaikwtaguogitiagzwxjiowiaxsomjiwxvljodivaxsotktgouikjowotjkscjvdjtuuoiwvjdtaiwogiaxvwonoadjvzcwltadztdowtagtjksixokxzjogidixtluogituvmilotaghotjtmlokvuczxiadutksiaolotjaiadrztaxzukvuczxiadwqwxounojiyiktxivatagkjqcxvdjtcsqtagiayvjutxivawokzjixq";

static constexpr char n_test_shift[]="gborbeabggborgungvfgurdhrfgvbajurguregvfaboyrevagurzvaqgbfhssregurfyvatfnaqneebjfbsbhgentrbhfsbegharbegbgnxrnezfntnvafgnfrnbsgebhoyrfnaqolbccbfvatraqgurzgbqvrgbfyrrcabzbernaqolnfyrrcgbfnljrraqgururnegnpurnaqgurgubhfnaqanghenyfubpxfgungsyrfuvfurvegbgvfnpbafhzzngvbaqribhgylgborjvfuqgbqvrgbfyrrcgbfyrrccrepunaprgbqernznlgurerfgurehosbevagungfyrrcbsqrngujungqernzfznlpbzrjurajrunirfuhssyrqbssguvfzbegnypbvyzhfgtvirhfcnhfrgurerfgurerfcrpggungznxrfpnynzvglbsfbybatyvsr\0";

////////////////////////////////////////////////////////////////////////////////

// Hash Map implementation 
template <typename T, typename M>
struct Node
{
  T key;
  M value;
};
template <typename T, typename M, uint32_t size>
struct HashMap
{
  //Node<T,M> *ListMap= new Node<T,M>[size];
  Node<T,M> ListMap[size];
  Node<T,M> *p_ListMap = ListMap;//= new Node<T,M>[size];
  //HashMap(std::initializer_list<Node<T,M> > n) {std::copy(n.begin(), n.end(),ListMap);};
  //HashMap(){free(ListMap);};
  M& operator[](T k) const
  {
    for(int i = 0; i< size; ++i)
      if(ListMap[i].key == k)
	return (p_ListMap + i)->value;
  };
  Node<T,M>& operator()(int index) const
  {
    return *(p_ListMap + index);
  };
  void shift(int len)
  {
    for(auto i=0;i<len; ++i)
      std::rotate(p_ListMap,p_ListMap+1,p_ListMap[size]);

  };
};
using AlphabetHash=HashMap<const char*, int,26>;
using AlphabetHashA=HashMap<int, int,26>;
///////////////////////////////////
// My gcd: assumes the values are in range of 32 bits
// I got help from this resource: https://cp-algorithms.com/algebra/euclid-algorithm.html
inline int _gcd(int x, int y)
{
  if(x == 0) return y;
  if(y == 0) return x;
  auto shift = __builtin_ctz(x|y);
  x >>= __builtin_ctz(x);
  do {
    y >>= __builtin_ctz(y);
    if(x>y)
      std::swap(x,y);
    y -=x;
  }while(y);
  return x << shift;
};

constexpr auto fast_mod(const int x, const int y)
{
  auto mod = x%y;
  if(mod<0)
    mod+=y;
  return mod;
};
constexpr float statistical_distance(const int& x, const int& y)
{
    return 0.5 * (x-y);
};
// Parameter is biagrams
constexpr auto ds(const char* x)
{
    int d=0,i = 0, j=0;
    while(i<26)
    {
     if(alphabet[i] == x[0])
       break;
     else
       ++i;
    }
    while(j<26)
    {
     if(alphabet[j] == x[1])
       break;
     else
       ++j;
    }

    return fast_mod(i-j, 26); //x-y
};
constexpr bool EqualityFunction(const char* t1,const char* t2)
{
    return !(t1 == t2);
};
constexpr uint32_t _strlen(const char* s)
{
  uint32_t i{0};
  while(*s++)
    ++i;
  return i;
}
std::vector<int> total_distance_arr;
template <uint32_t type>
inline uint32_t _find_match(const char reg[type+1], const char* s)
{
  uint32_t index{0};
  char temp[type+1];
  std::vector<int> index_arr;
  std::vector<int> distance_arr;
  do {
    for(int i=0;i<type+1;++i)
    {
      if(i == type)
	*(temp+i) = '\0';
      else
	*(temp+i) = *(s+i);
    }
    if(strcmp(temp,reg) == 0) 
      index_arr.push_back(index);
  ++index;
  } while (*s++);
  

  int previous = index_arr[0];
  if(index_arr.size() >1)
    std::for_each(index_arr.begin() + 1 , index_arr.end(), [&](int& n){
	  distance_arr.push_back(n - previous);	 
	  total_distance_arr.push_back(n-previous);
	  previous = n;
	});
  else
    return 1;
  int gcd = distance_arr[0];
  std::for_each(distance_arr.begin() + 1 , distance_arr.end(), [&](int& n){
	int temp = _gcd(n, gcd);
	if(temp !=1 )
	  gcd = temp;
      });
  return gcd;
}
template <uint32_t type>
inline auto kasiski_test(const char* input)
{
  Node<int, int> gcd_result;
  std::unordered_map<int,int> kasiski;

  const char *s = input;
  char temp[type+1];
  //null ended is a must
  uint32_t index_counter = 0;
  do{
    if(*s!=' ' && *(s+1) != ' ')
    {
      for(int i=0;i<type+1;++i)
      {
	if(i == type)
	  *(temp+i) = '\0';
	else
	  *(temp+i) = *(s+i);
      }
      if(kasiski.find(_find_match<type>(temp,input)) == kasiski.end())
	kasiski[_find_match<type>(temp,input)] = 1;
      else
	kasiski[_find_match<type>(temp,input)] += 1;
    }
  } while(*s++);
  return kasiski;
}


constexpr double coincidence_index_cipher(const char* inp, int offset= 0, int scale =1) 
{
  HashMap<char, double, 26> l_f={{
    {alphabet[0], 0} ,
    {alphabet[1], 0} ,
    {alphabet[2], 0} ,
    {alphabet[3], 0} ,
    {alphabet[4], 0} ,
    {alphabet[5], 0} ,
    {alphabet[6], 0} ,
    {alphabet[7], 0} ,
    {alphabet[8], 0} ,
    {alphabet[9], 0} ,
    {alphabet[10], 0},
    {alphabet[11], 0},
    {alphabet[12], 0},
    {alphabet[13], 0},
    {alphabet[14], 0},
    {alphabet[15], 0},
    {alphabet[16], 0},
    {alphabet[17], 0},
    {alphabet[18], 0},
    {alphabet[19], 0},
    {alphabet[20], 0},
    {alphabet[21], 0},
    {alphabet[22], 0},
    {alphabet[23], 0},
    {alphabet[24], 0},
    {alphabet[25], 0}
  }};
  int i = offset;
  int scaled_n = 0;
  int n = _strlen(inp);
  const char * it = inp;
  while( i < n)
  {
    l_f[it[i]] =l_f[it[i]] +1;
    i += scale;
    ++scaled_n;
  }
  int acc=0;
  for (int i =0; i< 26; ++i)
  {
      acc += l_f.ListMap[i].value * (l_f.ListMap[i].value-1);
  }
  return acc/static_cast<double>(scaled_n * (scaled_n-1));
};
constexpr auto calculate_frequency(const char* inp, int offset= 0, int scale =1) 
{
  HashMap<char, double, 26> l_f={{
    {alphabet[0], 0} ,
    {alphabet[1], 0} ,
    {alphabet[2], 0} ,
    {alphabet[3], 0} ,
    {alphabet[4], 0} ,
    {alphabet[5], 0} ,
    {alphabet[6], 0} ,
    {alphabet[7], 0} ,
    {alphabet[8], 0} ,
    {alphabet[9], 0} ,
    {alphabet[10], 0},
    {alphabet[11], 0},
    {alphabet[12], 0},
    {alphabet[13], 0},
    {alphabet[14], 0},
    {alphabet[15], 0},
    {alphabet[16], 0},
    {alphabet[17], 0},
    {alphabet[18], 0},
    {alphabet[19], 0},
    {alphabet[20], 0},
    {alphabet[21], 0},
    {alphabet[22], 0},
    {alphabet[23], 0},
    {alphabet[24], 0},
    {alphabet[25], 0}
  }};
  int scaled_n = 0;
  int n = _strlen(inp);
  int i = fast_mod(offset,n);
  const char * it = inp;
  while( i < n)
  {
    l_f[it[i]] =l_f[it[i]] +1;
    i += scale;
    ++scaled_n;
  }
  for (int i =0; i< 26; ++i)
      l_f.ListMap[i].value /= (scaled_n/100.0);// / 100;
  //for (int i =0; i< 26; ++i)
  //  std::cout << l_f.ListMap[i].key<< ","<<l_f.ListMap[i].value << "\n";
  return l_f;
};


constexpr HashMap<const char*, int,14> biagrams = {{
  {"th",ds("th")},
  {"an",ds("an")},
  {"er",ds("er")},
  {"es",ds("es")},
  {"ea",ds("ea")},
  {"at",ds("at")},
  {"en",ds("en")},
  {"he",ds("he")},
  {"in",ds("in")},
  {"re",ds("re")},
  {"on",ds("on")},
  {"ti",ds("ti")},
  {"st",ds("st")},
  {"nd",ds("nd")}}};

constexpr HashMap<char, int, 26> letter_indexes={{
  {alphabet[0], 0} ,
  {alphabet[1], 1} ,
  {alphabet[2], 2} ,
  {alphabet[3], 3} ,
  {alphabet[4], 4} ,
  {alphabet[5], 5} ,
  {alphabet[6], 6} ,
  {alphabet[7], 7} ,
  {alphabet[8], 8}  ,
  {alphabet[9], 9} ,
  {alphabet[10], 10},
  {alphabet[11], 11},
  {alphabet[12], 12},
  {alphabet[13], 13},
  {alphabet[14], 14},
  {alphabet[15], 15},
  {alphabet[16], 16},
  {alphabet[17], 17},
  {alphabet[18], 18},
  {alphabet[19], 19},
  {alphabet[20], 20},
  {alphabet[21], 21},
  {alphabet[22], 22},
  {alphabet[23], 23},
  {alphabet[24], 24},
  {alphabet[25], 25}
}};
constexpr HashMap<char, double, 26> letter_frequencies={{
  {alphabet[0], 8.2} ,
  {alphabet[1], 1.5} ,
  {alphabet[2], 2.8} ,
  {alphabet[3], 4.2} ,
  {alphabet[4], 12.7} ,
  {alphabet[5], 2.2} ,
  {alphabet[6], 2.0} ,
  {alphabet[7], 6.1} ,
  {alphabet[8], 7.0}  ,
  {alphabet[9], 0.1} ,
  {alphabet[10], 0.8},
  {alphabet[11], 4.0},
  {alphabet[12], 2.4},
  {alphabet[13], 6.7},
  {alphabet[14], 7.5},
  {alphabet[15], 1.9},
  {alphabet[16], 0.1},
  {alphabet[17], 6.0},
  {alphabet[18], 6.3},
  {alphabet[19], 9.0},
  {alphabet[20], 2.8},
  {alphabet[21], 1.0},
  {alphabet[22], 2.4},
  {alphabet[23], 0.1},
  {alphabet[24], 2.0},
  {alphabet[25], 0.1}
}};

int frequency_of_biagrams[26][26];
///////////////
// List w.r.t. textbook
enum siphers {shift = 0, substitution, vigenere, permutation};
struct Answer {int smallest_index; double smallest_difference;};
struct ClassicalSiphers
{
  explicit ClassicalSiphers(const char* m): message(strdup(m)){};

  static inline Answer chk_frequency_shift(const HashMap<char,double,26>& c_f){// c_f::cipher frequency
    int shiftlength=0;//Shift length
    HashMap<int,double,26> stat_distance_hash;
    for(int i =0; i<26;++i) //shift size, also index for letter frequencies
    {
      double frequency_count{0};
      //std::cout << "--------------------\n";
      for(int j =0; j<26;++j)
      {
	if(c_f(fast_mod(j-i,26)).value != 0)
	{
	  frequency_count = frequency_count + fabs(letter_frequencies(j).value - c_f(fast_mod(j-i, 26)).value);
	}
      }
      stat_distance_hash(i).key = i;
      stat_distance_hash(i).value = frequency_count * 0.5;
    }
    double smallest_difference{1000};
    int smallest_index = -1;
    //for (int i =0; i<26; ++i)
      //std::cout << stat_distance_hash(i).key << ","<< stat_distance_hash(i).value <<"\n";
    for (int i =0; i<26; ++i)
    {
      //std::cout << stat_distance_hash(i).key << "," << stat_distance_hash(i).value << "\n";
      if (smallest_difference > stat_distance_hash(i).value)
      {
	smallest_index = stat_distance_hash(i).key;
	smallest_difference = stat_distance_hash(i).value;
      }
    }
    //std::cout << "Decrypted shift value is: " << smallest_index<<" with value "<< smallest_difference <<"\n";
    return {smallest_index,smallest_difference};
  }
  inline void decrypt_shift(int shift)
  {
    char parsed_message[_strlen(message) + 1];
    const char *it = message;
    char *it_of_p = parsed_message;
    for(int i=0; i< strlen(message);++i)
    {
      if(message[i] == ' ')
	*(it_of_p+i) = *(it + i);
      else
      {
	int index_of_replacement = fast_mod(letter_indexes[*(it + i)] - shift, 26);
	//std::cout << index_of_replacement;	
	*(it_of_p + i) = letter_indexes(index_of_replacement).key; 
      }

    }
    printf("%s", parsed_message);
  };
  inline void decrypt_vigenere(const char* key, int key_length)
  {
    char parsed_message[_strlen(message) + 1];
    const char *it = message;
    char *it_of_p = parsed_message;
    int key_iterator = 0;
    int shift = 0, index_of_replacement =0;
    for(int i=0; i < _strlen(message);++i)
    {
      if(message[i] == ' ')
	*(it_of_p +i) = *(it+i);
      else
      {
	shift = letter_indexes[tolower(*(it+i))] - letter_indexes[tolower(*(key + key_iterator))];
	index_of_replacement = fast_mod(shift, 26);
	*(it_of_p + i) = letter_indexes(index_of_replacement).key; 
	key_iterator = fast_mod(++key_iterator, key_length);
      }
    }
    *(parsed_message + _strlen(message)) = '\n';
    std::cout << parsed_message;
    //printf("%s", parsed_message);
  };
  char* message;
  char *key;
};

//Global variables

//Shift is minus
int main()
{
  auto t1 = std::chrono::high_resolution_clock::now();
  std::cout <<"----------------------------------------------------------------------\n";
  std::cout << "Program has started\n";
  std::cout <<"----------------------------------------------------------------------\n";
  std::cout <<"Coincidence index of ciphers: \n" ;
  std::cout <<"Coincidence index of cipher 1 is : " << std::setprecision(9) << coincidence_index_cipher(n_text1) << "\n";
  std::cout <<"Coincidence index of cipher 2 is : " << std::setprecision(9) << coincidence_index_cipher(n_text2) << "\n";
  std::cout <<"----------------------------------------------------------------------\n";
  std::cout <<"Letter Frequencies in English are below\n";
  for (int i =0; i<26; ++i)
    std::cout << letter_frequencies.ListMap[i].key<< ","<<letter_frequencies[letter_frequencies.ListMap[i].key]<< "\n";
  /*
   * Test Vigenere
   *
   */
  ClassicalSiphers c(text1);
  uint32_t UPPER_KEY_LENGTH_ESTIMATE = 15;
  uint32_t LOWER_KEY_LENGTH_ESTIMATE = 2;
  std::cout <<"----------------------------------------------------------------------\n";
  std::cout <<"Vigenere example is running for test.\n";
  std::cout <<"----------------------------------------------------------------------\n";
  std::cout <<"Letter Frequencies of vigenere cipher are below\n";
  auto l_f_vigenere = calculate_frequency(n_text1);
  for (int i =0; i<26; ++i)
    std::cout << l_f_vigenere(i).key<< ","<<l_f_vigenere(i).value<<"\n";
  std::cout << "\n";
  std::cout <<"----------------------------------------------------------------------\n";
  std::cout <<"Key length is being calculated.\n";
  auto b_f_vigenere = kasiski_test<3>(n_text1); //biagrams
  std::map<int,int> ordered_kasiski(b_f_vigenere.begin(), b_f_vigenere.end());
  int key_length_vigenere = 0;
  int number_of_occurances = 0;
  for(auto i: ordered_kasiski)
  {
    std::cout << i.first << "," <<i.second<<"\n";
    if(i.first < UPPER_KEY_LENGTH_ESTIMATE && i.first > LOWER_KEY_LENGTH_ESTIMATE && i.second > number_of_occurances)
    {
      key_length_vigenere = i.first;
      number_of_occurances = i.second;
    }
  }
  std::cout << "Possible length of key is: " << key_length_vigenere << "\n";
  std::cout <<"----------------------------------------------------------------------\n";

  std::cout <<"Letter frequencies of every "<< key_length_vigenere<<"th word" <<"\n";
  char* key_value = (char*) malloc(sizeof(char)*key_length_vigenere +1);
  int ITER_NO= key_length_vigenere * 1000 + 1;
  double fitness{0};
  std::vector<double> fitness_vector;
  std::vector<char*> fitness_keys;
  for(int offset=0; offset<ITER_NO; ++offset)
  {
    auto key_vigerenere_text = calculate_frequency(n_text1, offset,key_length_vigenere);
    auto possible_shift_value_for_vigenere = ClassicalSiphers::chk_frequency_shift(key_vigerenere_text);
    *(key_value + fast_mod(offset,key_length_vigenere)) = alphabet[fast_mod(0-possible_shift_value_for_vigenere.smallest_index, 26)];
    fitness += possible_shift_value_for_vigenere.smallest_difference;
    if(offset % key_length_vigenere == 0)
    {
      fitness_vector.push_back(fitness);
      fitness_keys.push_back(key_value);
      //std::cout <<"Key is: " << key_value<<"\n";
      //std::cout <<"Fitness is: " << std::setprecision(9) << fitness << "\n";
      fitness = 0;
    }
  }
  key_value = fitness_keys[std::min_element(fitness_vector.begin(),fitness_vector.end()) - fitness_vector.begin()];
  *(key_value + key_length_vigenere) = '\n';
  std::cout <<"Key is: " << key_value;
  //for (int i =0; i<26; ++i)
  //  std::cout << key_vigerenere_text(i).key<< ","<< key_vigerenere_text(i).value<<"\n";
  std::cout <<"--------------------------------------------------------------------\n";
  std::cout <<"Decryption starts now.\n";
  c.decrypt_vigenere(key_value, key_length_vigenere);
  std::cout <<"********************************************************************\n";
  free(key_value);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  std::cout << "Duration of program is: " << 0.000001 * duration << "seconds.\n" ;

  return 0;
}
