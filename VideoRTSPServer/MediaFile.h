#pragma once
#include "base.h"

class MediaFile
{
public:
	MediaFile();
	~MediaFile();

	int Open(const CBuffer& path,int type = 96);
	//���Cbuffer.size()==0��˵��û��֡��
	CBuffer ReadOneFrame();
	void Close();
	//���ú�,ReadOneFrame�ֻ���ֵ����
	void Reset();

private:
	long FindH264Head();
	CBuffer ReadH264Frame();
private:
	FILE* m_file;
	long m_tail;
	CBuffer m_filepath;
	//96 H264
	int m_type;
};

