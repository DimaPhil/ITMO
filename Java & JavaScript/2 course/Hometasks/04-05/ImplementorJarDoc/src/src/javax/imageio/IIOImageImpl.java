package javax.imageio;

class IIOImageImpl extends javax.imageio.IIOImage {

    public IIOImageImpl(java.awt.image.Raster x0, java.util.List x1, javax.imageio.metadata.IIOMetadata x2) {
        super(x0, x1, x2);
    }

    public IIOImageImpl(java.awt.image.RenderedImage x0, java.util.List x1, javax.imageio.metadata.IIOMetadata x2) {
        super(x0, x1, x2);
    }

    private static native void registerNatives();


}
