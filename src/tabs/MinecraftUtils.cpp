/*
 * Shared_Utils.cpp
 *
 *  Created on: Aug 27, 2012
 *      Author: mgooch
 */
#include "MinecraftUtils.h"

//TODO change this so that it uses wxXmlDocument class instead

void MinecraftUtils::UpdateList(wxListCtrl* list,wxArrayString& data)
{
	list->DeleteAllItems();
	for(size_t i=0; i<data.Count(); ++i)
	{
		list->InsertItem(i,data[i]);
		//wxLogMessage(data[i]);
	}
}
void MinecraftUtils::UpdateList(wxListCtrl* list,std::vector<wxArrayString>& data)
{
	list->DeleteAllItems();
	for(size_t i=0; i<data.size(); ++i)
	{
		list->InsertItem(i,data[i][0]);
		list->SetItem(i,1,data[i][1]);
		//wxLogMessage(data[i][0]+wxT("\t")+data[i][1]);
	}
}

bool MinecraftUtils::Read1ColFile(wxFileName& filename,wxArrayString& data)
{

	wxString line,tmp;
	data.Clear();
	if(filename.FileExists())
	{
		wxTextFile file(filename.GetFullPath());
		if(file.Open())
		{
			for(size_t i=0; i < file.GetLineCount(); ++i)
			{
				if(!file[i].IsEmpty())
				{
					data.Add(file[i]);
				}
			}
			file.Close();
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}

bool MinecraftUtils::ReadNColFile(wxFileName& filename,std::vector<wxArrayString>& data, size_t cols)
{
	wxString line;
	data.clear();
	if(filename.FileExists())
	{
		wxTextFile file(filename.GetFullPath());
		if(file.Open())
		{
			for(size_t i=0; i < file.GetLineCount(); ++i)
			{
				wxArrayString arr=wxSplit(file[i],'\t');
				if(arr.Count()==cols)//require # ofcols
				{
					if(!arr[0].IsEmpty())
					{
						data.push_back(arr);    //first entry can't be empty
					}
				}
			}
			file.Close();
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}

bool MinecraftUtils::Write1ColFile(wxFileName& path, wxArrayString& data)
{
	wxTextFile file(path.GetFullPath());
	if(file.Exists())
	{
		file.Open();
		file.Clear();
	}
	else
	{
		file.Create();
		file.Open();
		file.Clear();
	}
	if(file.IsOpened())
	{
		for(size_t i=0; i<data.Count(); ++i)
		{
			file.AddLine(data[i]);
		}
		if(!file.Write())
		{
			return false;
		}
		file.Close();
		return true;
	}
	else
	{
		return false;
	}
}

bool MinecraftUtils::WriteNColFile(wxFileName& path, std::vector<wxArrayString>& data,size_t cols)
{
	wxTextFile file(path.GetFullPath());
	if(file.Exists())
	{
		file.Open();
		file.Clear();
	}
	else
	{
		file.Create();
		file.Open();
		file.Clear();
	}
	if(file.IsOpened())
	{
		for(size_t i=0; i<data.size(); ++i)
		{
			wxString line;
			for(size_t j=0; j<cols; ++j)
			{
				line+=data[i][j];
				if(j+1 != cols)
				{
					line+=wxT("\t");
				}
			}
			file.AddLine(line);
		}
		if(!file.Write())
		{
			return false;
		}
		file.Close();
		return true;
	}
	else
	{
		return false;
	}
}
bool MinecraftUtils::GetFile(wxString& URL, wxFileName& dest)
{
	CURL *curl;
	CURLcode res;
	wxString response;
	if(!dest.DirExists() && !dest.Mkdir(wxS_DIR_DEFAULT,wxPATH_MKDIR_FULL)){return false;}//TODO error message why it failed. dir doesn exist && couldnt be created
	wxString fname=dest.GetFullPath();
	FILE* data=fopen(fname.c_str(),"w");//TODO open REAL file here.
	if(data == NULL){return false;}//TODO error message for file could not be created/opened
	bool OK = true;

	/* In windows, this will init the winsock stuff */

	/* get a curl handle */
	curl = curl_easy_init();
	if (curl) {
		/* First set the URL that is about to receive our POST. This URL can
			 just as well be a https:// URL if that is what should receive the
			 data. */
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
		/* Now specify the POST data */
		/* Perform the request, res will get the return code */
		curl_easy_setopt(curl, CURLOPT_URL, URL.char_str().data());
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			OK = false;
		}

		/* always cleanup */
		curl_easy_cleanup(curl);
	} else {OK=false;}
	int close_result=fclose(data);
	if(close_result){
		std::wcout<<"close failed with value: "<<close_result<<std::endl;
		return false;
	}
	return OK;
}

bool MinecraftUtils::GetPageContent(wxString& URL, std::string& page) {
	CURL *curl;
	CURLcode res;
	std::string response;
	bool OK = true;

	/* In windows, this will init the winsock stuff */
	/* get a curl handle */
	curl = curl_easy_init();
	if (curl) {
		/* First set the URL that is about to receive our POST. This URL can
		 just as well be a https:// URL if that is what should receive the
		 data. */
		std::stringstream ss;
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ss);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &get_string_from_curl);
		/* Now specify the POST data */
		/* Perform the request, res will get the return code */
		curl_easy_setopt(curl, CURLOPT_URL, URL.char_str().data());
		res = curl_easy_perform(curl);
		response=ss.str();//TODO check that this works on windows
		/* Check for errors */
		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			OK = false;
		}
		//std::wcout<<wxT("page content: ")+response);

		/* always cleanup */
		curl_easy_cleanup(curl);
	} else {OK=false;}

	page = response;
	return OK;
}

size_t MinecraftUtils::get_string_from_curl(char *ptr, size_t size,
		size_t nmemb, void *userdata) {
	std::stringstream& ss = (*((std::stringstream*) userdata));
	for (size_t i = 0; i < size * nmemb; ++i) {
		ss<< *ptr;
		ptr++;
	}
	return size * nmemb;
}

bool ConfirmFile(wxString& parentpath,wxFileName& file,wxString& etag)
{
	return true;
}

XMLEntity* XML_Handler::ParsePage(wxString& URL){
	XMLEntity* retval= new XMLEntity(NULL);
	this->currentpage=retval;
	this->ptr=retval;
	this->ptr->istag=true;
	this->ptr->text=wxT("DOC_ROOT");
	if (! retval) {
		fprintf(stderr, "Couldn't allocate memory for xml entity\n");
		exit(-1);
	}
	XML_Parser p = XML_ParserCreate(NULL);
	if (! p) {
		fprintf(stderr, "Couldn't allocate memory for parser\n");
		exit(-1);
	}
	//XML_UseParserAsHandlerArg(p);
	XML_SetElementHandler(p, start_hndl, end_hndl);
	XML_SetCharacterDataHandler(p, char_hndl);
	XML_SetUserData(p,this);
	//get page
	std::string page;
	bool success=MinecraftUtils::GetPageContent(URL,page);
	if(!success){return NULL;}
	//page obtained
	//get buffer to parse page with
	char * buffer=(char *)XML_GetBuffer(p,page.length());
	//read into buffer;
	memcpy(buffer,page.c_str(),page.length());
	//parse page
	int result=(XML_ParseBuffer(p, page.length(), 1));
	if(!result){
		//TODO handle error
	}
	this->currentpage=NULL;
	//free resources associated with parser
	XML_ParserFree(p);
	return retval;
}

XML_Handler::XML_Handler() : eventcnt(0),depth(0),currentpage(NULL),ptr(NULL){}
XML_Handler::~XML_Handler(){}

void XML_Handler::start_hndl(void *userdata,const XML_Char* el, const XML_Char**attr){
	XML_Handler* hndlr=(XML_Handler*)userdata;
	//std::wcout<<"START HANDLER CALLED @ depth"<< hndlr->depth<<std::endl;
	hndlr->depth++;//add layer to depth
	hndlr->eventcnt++;//add to count of events
	if(! (hndlr->ptr)){
		std::wcout<<"hndlr->ptr somehow become NULL!"<<std::endl;
		return;
	}
	//allocate new entity, auto setting its parent
	XMLEntity* entity=new XMLEntity(hndlr->ptr);
	if (! entity) {
		fprintf(stderr, "Couldn't allocate memory for xml entity\n");
		exit(-1);
	}
	//std::wcout<<"\telement name:\""<<el<<'"'<<std::endl;
	//add entity to vector of children of last nonterminated entity

	//hndlr->ptr->children.push_back(entity);

	//set ptr of last nonterminated entity to new entity
	hndlr->ptr=entity;
	//set text value to tag name
	(entity->text)=el;
	(entity->istag)=true;
	wxString key,val;
	//place ATTR values into map as wxString pairs
	const XML_Char* atrptr;
	for(size_t i=0;attr[i];i+=2)
	{
		key=attr[i];
		val=attr[i+1];
		entity->attrs[key]=val;
	}
}
void XML_Handler::end_hndl(void *userdata, const XML_Char *el){
	XML_Handler* hndlr=(XML_Handler*)userdata;
	//std::wcout<<"END HANDLER CALLED @ depth"<< hndlr->depth<<std::endl;
	hndlr->depth--;//remove one layer from depth
	hndlr->eventcnt++;//add to count of events
	//set ptr to last nonterminated entity to the terminated entity's parent
	hndlr->ptr=hndlr->ptr->parent;
	//std::wcout<<"\tCurrent Tag shifted upward to:"<< hndlr->ptr->text<<std::endl;
	//TODO check if end matches last start
}
void XML_Handler::char_hndl(void *userdata, const XML_Char *txt, int txtlen){
	XML_Handler* hndlr=(XML_Handler*)userdata;
	//std::wcout<<"TEXT HANDLER CALLED @ depth"<< hndlr->depth<<std::endl;
	XMLEntity* entity=NULL;
	XML_Char str[txtlen+1];
	memcpy(str,txt,sizeof(XML_Char)*txtlen);
	str[txtlen]='\0';
	//std::wcout<<"\ttext to handle:\""<<str<<'"'<<std::endl;
	bool lastistext;
	if(hndlr->ptr->istag && hndlr->ptr->children.size()>0){
		lastistext=!( ( hndlr->ptr->children[ (hndlr->ptr->children.size()-1) ] )->istag);
	} else {lastistext=false;}

	if(lastistext){
		entity=(hndlr->ptr->children[ (hndlr->ptr->children.size()-1) ]);
	} else {
		//if last added wasn't text, need new entity
		//allocate new entity, auto setting its parent
		entity=new XMLEntity(hndlr->ptr);
		if (! entity) {
			fprintf(stderr, "Couldn't allocate memory for xml entity\n");
			exit(-1);
		}
		//entity is not a tag
		(entity->istag)=false;
	}
	//std::wcout<<"\tappending text"<<std::endl;
	(entity->text)+=str;//add text content to text variable
	//std::wcout<<"\ttext is now: "<<(entity->text)<<std::endl;
}

XMLEntity::XMLEntity(XMLEntity* p){
	this->parent=p;
	this->istag=true;
	if(this->parent){this->parent->children.push_back(this);}
}

XMLEntity::~XMLEntity(){
	//TODO delete all children
	XMLEntity* child=NULL;
	for(size_t i =0 ;i < children.size();++i)
	{
		child=children[i];
		children[i]=NULL;
		if(child){delete child;}
	}
}

wxString XMLEntity::GetContainedXMLText(){
	wxString txt;
	wxString opentag;
	wxString closetag;
	wxString attribs;
	wxString tabs;
	size_t depth=0;
	wxString middletxt;
	for(XMLEntity* ptr=this;ptr->parent;ptr=ptr->parent,depth++,tabs+="\t")
	{}
	//std::wcout<<tabs+wxT("reconstructing XML text from XML_Entity")<<std::endl;
	//std::wcout<<tabs+wxT("depth computed to be: ")<<depth<<std::endl;
	if(this->istag)
	{
		//std::wcout<<tabs+wxT("Node is a tag, getting text from children")<<std::endl;
		//std::wcout<<tabs+this->text+wxT(" Node has ")<<this->children.size()<<wxT(" children")<<std::endl;
		for(size_t i=0;i<this->children.size();i++)
		{
			middletxt+=children[i]->GetContainedXMLText();
		}
		//std::wcout<<tabs+wxT("reconstructing attribs strings")<<std::endl;
		for(std::_Rb_tree_iterator<std::pair<const wxString,wxString> > i=this->attrs.begin();!(i == this->attrs.end());++i){
			attribs+=+ wxT(" ") + i->first + wxT("=\"") + i->second+ wxT("\"") ;
		}
		//std::wcout<<tabs+wxT("creating opentag")<<std::endl;
		opentag=tabs+wxT("<")+this->text+attribs+wxT(">\n");
		//std::wcout<<tabs+wxT("creating closetag")<<std::endl;
		closetag=tabs+wxT("</")+this->text+wxT(">\n");
		//std::wcout<<tabs+wxT("combining all text")<<std::endl;
		txt=opentag+middletxt+closetag;
	} else {
		//std::wcout<<tabs+wxT("Node is NOT a tag, getting text content")<<std::endl;
		txt=tabs+(this->text)+wxT("\n");;
	}
	return txt;
}
