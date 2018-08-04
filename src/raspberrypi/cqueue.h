//---------------------------------------------------------------------------
//
//	X68000 EMULATOR "XM6"
//
//	Copyright (C) 2001-2004 �o�h�D(ytanaka@ipc-tokai.or.jp)
//	[ MFC �L���[ ]
//
//---------------------------------------------------------------------------

#if !defined(queue_h)
#define queue_h

//===========================================================================
//
//	�L���[
//
//===========================================================================
class CQueue
{
public:
	// �����f�[�^��`
	typedef struct _QUQUEINFO {
		BYTE *pBuf;						// �o�b�t�@
		DWORD dwSize;					// �T�C�Y
		DWORD dwMask;					// �}�X�N(�T�C�Y-1)
		DWORD dwRead;					// Read�|�C���^
		DWORD dwWrite;					// Write�|�C���^
		DWORD dwNum;					// ��
		DWORD dwTotalRead;				// ���vRead
		DWORD dwTotalWrite;				// ���vWrite
	} QUEUEINFO, *LPQUEUEINFO;

	// ��{�t�@���N�V����
	CQueue();
										// �R���X�g���N�^
	virtual ~CQueue();
										// �f�X�g���N�^
	BOOL FASTCALL Init(DWORD dwSize);
										// ������

	// API
	void FASTCALL Clear();
										// �N���A
	BOOL FASTCALL IsEmpty()	const		{ return (BOOL)(m_Queue.dwNum == 0); }
										// �L���[���󂩃`�F�b�N
	DWORD FASTCALL GetNum()	const		{ return m_Queue.dwNum; }
										// �L���[�̃f�[�^�����擾
	DWORD FASTCALL Get(BYTE *pDest);
										// �L���[���̃f�[�^�����ׂĎ擾
	DWORD FASTCALL Copy(BYTE *pDest) const;
										// �L���[���̃f�[�^�����ׂĎ擾(�L���[�i�߂Ȃ�)
	void FASTCALL Discard(DWORD dwNum);
										// �L���[��i�߂�
	void FASTCALL Back(DWORD dwNum);
										// �L���[��߂�
	DWORD FASTCALL GetFree() const;
										// �L���[�̋󂫌����擾
	BOOL FASTCALL Insert(const BYTE *pSrc, DWORD dwLength);
										// �L���[�ɑ}��
	void FASTCALL GetQueue(QUEUEINFO *pInfo) const;
										// �L���[���擾

private:
	QUEUEINFO m_Queue;
										// �������[�N
};

#endif	// queue_h
