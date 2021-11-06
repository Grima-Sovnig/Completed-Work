import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class TSharkDataTest {

    private TSharkData data;

    @Before
    public void setUp(){
    }

    @Test
    public void getFrameNumber(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Frame Number - Line 8", "8", data.getFrameNumber());
    }

    @Test
    public void getFrameTime(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Frame Time - Line 8", "1.774700000", data.getFrameTime());
    }

    @Test
    public void getProtocol(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Protocol - Line 8", "TCP", data.getProtocol());
    }

    @Test
    public void getProtocolID(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Protocol ID - Line 8", "6", data.getProtocolID());
    }

    @Test
    public void getSrcIP(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Src IP - Line 8", "192.168.68.126", data.getSrcIP());
    }

    @Test
    public void getSrcPort(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Src Port - Line 8", "55358", data.getSrcPort());
    }

    @Test
    public void getDstIP(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Dst IP - Line 8", "52.114.159.112", data.getDstIP());
    }

    @Test
    public void getDstPort(){
        data = new TSharkData("\"8\",\"1.774700000\",\"TCP\",\"6\",\"192.168.68.126\",\"52.114.159.112\",\"55358\",\"443\",,");
        assertEquals("Dst Port - Line 8", "443", data.getDstPort());
    }
}