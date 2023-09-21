#include "pch.h"
#include "VideoClientController.h"

std::string VideoClientController::Unicode2Utf8(const std::wstring& strIn)
{
	return m_vlc.Unidcode2Utf8(strIn);
}



int VideoClientController::Init(CWnd*& pWnd)
{
	pWnd = &m_dlg;
	return 0;
}

int VideoClientController::Invoke()
{
	INT_PTR nResponse = m_dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}
	return nResponse;
}

int VideoClientController::SetMedia(const std::string& strUrl)
{
	return m_vlc.SetMedia(strUrl);
}


float VideoClientController::VideoControl(CVlcCommand cmd)
{

	switch (cmd)
	{
	case CVLC_PLAY:
		return (float)m_vlc.Play();
		
	case CVLC_PAUSE:
		return (float)m_vlc.Pause();
	case CVLC_STOP:
		return (float)m_vlc.Stop();
	case CVLC_GET_VOLUME:
		return (float)m_vlc.GetVolume();
	case CVLC_GET_POSITION:
		return m_vlc.GetPosition();
	case CVLC_GET_LENGTH:
		return m_vlc.GetLength();
	default:
		return -1.0;
	}
}

int VideoClientController::SetHwnd(HWND hwnd)
{
	return m_vlc.SetHwnd(hwnd);
}


int VideoClientController::SetVolume(int volume)
{
	return m_vlc.SetVolume(volume);
}

int VideoClientController::SetPosition(float pos)
{
	return m_vlc.SetPosition(pos);
}


VlcSize VideoClientController::GetMediaInfo()
{
	return m_vlc.GetMediaInfo();
}
