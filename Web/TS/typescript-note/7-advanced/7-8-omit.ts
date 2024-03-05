{
  type Video = {
    id: string;
    title: string;
    url: string;
    data: string;
  };

  type VideoMetaData = Omit<Video, 'url' | 'data'>;

  function getVideo(id: string): Video {
    return {
      id,
      title: 'video',
      url: 'https://',
      data: 'byte-data..',
    };
  }

  function getVideoMetaData(id: string): VideoMetaData {
    return {
      id,
      title: 'title',
    };
  }
}
