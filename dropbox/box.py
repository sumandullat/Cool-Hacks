import dropbox
import sys

SECRET_KEY_FOR_API = 'API key'

class TransferData:
    def __init__(self):
        self.access_token = SECRET_KEY_FOR_API
        self.dbx = dropbox.Dropbox(self.access_token)

    def upload_file(self, file, remote_name):
        self.dbx.files_upload(file, remote_name)
        meta = self.dbx.sharing_create_shared_link(remote_name)
        url = meta.url
        url = url.replace('?dl=0', '?dl=1')
        return url

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: python box.py [file1] [file2] ...')
    else:
        files = sys.argv[1:]
        sender = TransferData()
        for i in files:
            try:
                archive = open(i, 'rb')
                url = sender.upload_file(archive.read(), '/'+i)
                print(i, 'upload successful. URL:', url)
            except:
                print('Error during upload of', i)
