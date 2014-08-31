// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "db.h"
#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
		(      0, hashGenesisBlockOfficial )   
		(   1000, "0000038b17a6632ca255d9174c1aa58d50b18c3e988bc353bbb9ecedf1cc18af")
		(   2000, "000000463138d1946484643b0ab6dd1788bab56357cfdbacdcf9139f9682656f")
		(   3000, "0000018e2fb0b50f51dbae6035fd0852c2598e97caac3418c2c498f4e106bd66")
		(   4000, "00000005c1aa69efddc7623704e3874e317eed248666c98aeb0456e50e75da00")
		(   5000, "00000080152fc04068ce80b53357c1bc619bb2c827c50c721ca2938d144c9811")
		(   6000, "0000001248453d054c87b5da4cdea7f48dc517fef7da266f8f9f69e6e65e4c4e")
		(   7000, "000000412ea2d87c864633e8f668b3590f097949813a394a6458e3a283a39cd9")
		(   8000, "000000c5bb090f480b7bbdc28b7e236a256c5714e84a636b65303acfa619b544")
		(   9000, "000000160f563f221e1a3b8a4056a2c59bc7b6bcab6492608e49811da629f58f")
		(  10000, "000000a4112d231a04bbfd1da68072ef347f78de2b21a0984d5e6cf272d1952f")
		(  11000, "0000000e7681fe97fb909cdae79f424489a4bbba00ad399027c55805912b1660")
		(  12000, "000000544c1bf9c3232b8bc565a7c1afae8ed5c95d68edc1ea339b6692eece64")
		(  13000, "00000041f49c47087335294b615fcd751e5053d00a8057f2a7e8be7d76e6901d")
		(  14000, "0000002b2b38b3085d2361e2f6d61352156aac8f9e0bcab85ab4dff9f24216e3")
		(  15000, "0000003c296d714029365f56c83894e23c1adfa1d30f16dbfda973eb10cf79fa")
		(  16000, "0000003cf006135bb88b463e063fc8b5e4a7478e1d673f6aa6c131264bf0bfcb")
		(  17000, "000000183efe0887c5b771c37d51bc64ecda563e771550e72d948836b89bef2d")
		(  18000, "000000128f283f394d5aa4589e52f5f60f493e6d218e90dd487e9ba349a7e662")
		(  19000, "00000004f3af620f887ec76032392e4772356a455137fdd2b2b4073dff4987f0")
		(  20000, "000000221af9d31004d8a7c2928bb4e8980fae13ccfe4c99acd81243611a3f77")
		(  21000, "00000005a8c869b35a836820e34a4a9113b1c9b45ba67cf2bc5138063290afeb")
		(  22000, "00000002f008cd5589180d64a56af223794fcb46584125207d16be7d54608cdd")
		(  23000, "00000001723daaed521ec9b7a3014951b5e637e43acbf9aa5e995259996e6e74")
		(  24000, "00000008ee614577fa60e70674839db772f9a770e9cd4f973c5f6868faa2da16")
		(  25000, "00000004010aa00e32846de638b4416607a0fd85ebdab9a64f0f4ab49f8562e4")
		(  26000, "0000000190303432b769267e03726452618defedc899b1e9c1fe4fda58f30dff")
		(  27000, "0000000084184a17921af84779ff84574bb74515be7f5bef4d7ad0c69f82f98a")
		(  28000, "000000005c3fa206deaea8926686ea2028d5f95f7462a3d5426149876f07e6c4")
		(  29000, "0000000054776a851e7bfddf1abc9e404bb0712b1bb3d38e28860ad9b7a8be18")
		(  30000, "00000000240ad8d38df4f272341ef0217c349adceb852b4090ff735cf33489c7")
		(  31000, "0000000008744df71a662d2b3cb9e8ab002f9914a82c738ec0c53827d85a92f5")
		(  32000, "000000004b028b4ee96000675d17596681b0e59420beff26530908e0e24904a1")
		(  33000, "00000000004541dc783a9e3d0d36acf14adc68d026e9d548ea92e2251501f4e4")
		(  34000, "0000000039217eba6fd941107c31d54e8880ee004b45c09f7387e90312e56e71")
		(  35000, "0000000033a03c97069d69a10a18bda6b244eb05ab6def91af19353593372f54")
		(  36000, "000000002eabd2deb8225438e92a3fe4c93fb4175075191a5570486691f50d50")
		(  37000, "000000003a4ce364e76153677a052c3ab8ba6b7e408b0e56d0812c88cb685a36")
		(  38000, "0000000036534e71c42fae84cd979270766ed57c3c8521a4f2f133f12d9d5a65")
		(  39000, "000000005332ae90772336700c96cb85c016f172e6beec4440bbd06bdc8a72a9")
		(  40000, "00000000bb30814b04e248922f0929b078c9ef2c8b7c8c6eb4d38cfbc4cacaea")
		(  41000, "0000000060bb2d9771e0ce6cd205e543991cf8d2c9d5021e103fe942b9cd564b")
		(  42000, "00000000152b8bf8657f7c3a32068a7e42ef44b1e326146920d7ddacd8bb066e")
		(  43000, "00000000298d05d1b820ea9b962352fba5527e75ce15ff50bfd3c262e167959a")
		(  44000, "000000000423f91df7bb6113b7e2c48bd1a7653d5eb8c24ba086d7c041b8edf9")
		(  45000, "00000000641425ac7bf14e13ed5ba782ada11410946b83fb7de8ee30898ce0a8")
		(  46000, "0000000020804629ebbfa346a4bce6953d1fb031ae2aa57b5ab7e06874f56fab")
		(  47000, "0000000064d9b2023778f81068d609730e3c8ae3da39f189b0a778e9cc4f642e")
		(  48000, "000000007ca11745aafa0082e9f7d6fc76b3bd3534329085a9e2e55ce5d33ddf")
		(  49000, "00000000a0e3efdd49e87c652f514501ed37f879441b7bfe2704ccee81e92b7e")
		(  50000, "000000001c3e13ae6c9ad5fb4a3afec813904b6dfeff549cb0a2afb07314f85d")
		(  51000, "000000004359116bd3131bbb00457cd2312da79f5079f22c7a69771b16405144")
		(  52000, "000000003d95e7cbe1fa99e7625ff8e140f56fde0cc89ee67ae0bec1ac7ae036")
		(  53000, "0000000099b57e1d51cb06f4756b6ce0edfe098b540cf6fa68a6dc60a030d581")
		(  54000, "0000000005b8a93da7d9c64cd1957c16cd50dda4fd683fb9950799add31f1859")
		(  55000, "000000009c3409102c22a8532d57720ae5a618d5f6e21c2a2ab15e4586394786")
		(  56000, "00000000031435d395b0e271efa88bd4c2658057db5a7fe7715eddc360b3af89")
		(  57000, "0000000041ae4f793990b309f73fb26ebb6ff957e3c9950245687ef6dde47ff4")
		(  58000, "000000005a6d52a453a64d064e2a1768392ee3d623a5eab721eb66684eea8677")
		(  59000, "000000005bcd9f1276c2110371309e227a033498686489049d2609386c5b5d86")
		(  60000, "00000000584f97d73d852b3109b3820a29bc9276458ada99e348d7e2a17208f1")
		(  61000, "00000000069fe6b53a9967e27f85063b1056a3e7a44690cad533b2b95d55de3b")
		(  62000, "000000003a239741e375e222f027615869474d59dc5498a04c809deeedaa61b3")
		(  63000, "000000003e5f56ce72862b6d1d5843832f2c542b02bf8d76f857df7fff6ba6d9")
		(  64000, "000000001436d4712cf5786014f8c448f28b65a215ad967a744e02d5e9f3d238")
		(  65000, "0000000049e0f9d7b9575984cabf33509bf7f438923211d2f7cb63103f65da81")
		(  66000, "0000000071a0a24ad9a272da3750a86290f0730d7ab34a446a5d9d7a02096194")
		(  67000, "000000002d5a630c61ed00b2ad37a473f30961549ada5996ef27d652fef90535")
		(  68000, "0000000015da6d2712723eb003f4ba4f0f41078af801d69e9e873220db288a0f")
		(  69000, "00000000569a54cd27b2f63a35fa6b986c776fa0d89ceac5844aa8ba60d887a1")
		(  70000, "000000001113f157b8a4473ffb836fff61a72ab52a20aefdd3d5d82dfb6ba6ec")
		(  71000, "00000000179634fa091ac17e8b1991c028c8eec46325cb59f226a3424201d81c")
		(  72000, "00000000165bc63c404ccc828351e58d23bc7e93333c7e9c1e6e1c397279edc1")
		(  73000, "000000004e7c1f56285cdb7bc08f256ab00ba4ac022344f42e60d3e0316b45f1")
		(  74000, "0000000034f77d76ca718bd7cce0439ec03f85c8895d6523c42e9baa7bfa3720")
		(  75000, "000000007fb7061a164108466b2045e9d7a7ad08d9b60b951d6daf5b0a75da75")
		(  76000, "de69978fd8b6e6c6d30b6e73b2787201234b43ac30a76cd6b9e56ad2142ac54a")
		(  77000, "0000000078ddbda21326d62aa7d13618e318de4276b12448cfe02a14f8f3ede0")
		(  78000, "00000000525887a8b4acbe1ab281cfdc877fd196e32aee2fd408bc0318f6f25e")
		(  79000, "00000000205118c32b2005d4531e41f22f3026a44a6169b1459c5f2e2bdc01e3")
		(  80000, "000000008f41d387442af8201e0cb442bc574c5307a914cbd8cad58fb885c640")
		(  81000, "000000003f18fc87ecaa915a9e56d70f6ad284a10b07b385102bc69508060e15")
		(  82000, "0000000002124ca0288ed3ff61b5de9e0874d0064945ed543cd5c3128ffd2d27")
		(  83000, "00000000a2e01698a6c99151d5a5d5bb6b269fa87a81a8d7f2eb59c3713c2467")
		(  84000, "0000000011fe4dfb89b31a991e11b0c050760d9b721d7fc5430c79c79668b158")
		(  85000, "000000004f6285f5784de31f9612b1a443c0e04c1a51c467eaffea7a8e014817")
		(  86000, "0000000092b3537fe2e751e427fdf355b88cfc9d004fd08a25ca43ca795ac1f5")
		(  87000, "0000000076e007efda107077175f8d10763579fdb0a530f41bd99ca866a757d5")
		(  88000, "000000003f2a33d03e7bc22ec4cb14582307eb53aa5856690958abf95061a6ed")
		(  89000, "000000004290a95f24e9b2208b33a5bc6147c1f5507859636bd436b289ebb0ac")
		(  90000, "0000000057e1d9a8c216ad5ff5158401d2409b6d1a67091ac2dcd2b938f2ee36")
		(  91000, "000000007a1540fd92ef1da9ecb43aa4e93de227a1eedc59f8f9755d171569db")
		(  92000, "000000015fc4728be684adca73bd0c923e80f7fd206dbec9e158d006aace7d92")
		(  93000, "0000000017bc2afe919f6aa11b4458e15fd38b7422359643df2905b43a189e78")
		(  94000, "000000008594efb2a6ab7a38a0f944c61e2f45472a1d3e69ffe6fe65a2263a8a")
		(  95000, "000000006e7377074566a9793c849470c4d3d1334c8adb981242df56f86e8ad9")
		(  96000, "000000007c5d7024c6289c52ecaed2793a1c5a0ba415b0d50d0afa32bef4c399")
		(  97000, "00000000adc70b02eb43e8f4d76dc0776afa34f635f15af48ad5ae193055f98b")
		(  98000, "0000000083f4461489be39fde342fd410e089cf17f772126b2006edf51ddceca")
		(  99000, "000000011de311b2704d37c92ad3ff23326815d2221040e6c5ff56e8272e66f6")
		( 100000, "00000000a428e3fb89cd3216047226c5db2c2b5c7508e910db28443f56b6a718")
		( 101000, "0000000082f3aa6bef7aea5e86ac9d2a215a518ae3aac6022609b0e258689e76")
		( 102000, "000000005aa9bfa2623236f114168d821f306f75487d5eae8a8fbfce41791614")
		( 103000, "00000000c4d2acf8fc405ffc552c231530c462e4b0c7cd6d479f216db096cbab")
		( 104000, "00000000550b0f9806e675708355d10eb4fedc895498beee61b398469afcceec")
		( 105000, "000000001012cda0b91bda5ba5c7f8b4f1c34d0df39a28a0e5b1cc0d82edc0c5")
		( 106000, "00000000ff8e50754e4ecbe3b2d54499f25fc0b5b4d3e6e6b48f6eeb1bdea128")
		( 107000, "000000003bc988f596631ddd6d3402ff82fb145fd5233ac606a3fb133a44fb1e")
		( 108000, "000000008c11a95039511f292926a95212f88dac08a08563a15d6886440d95e6")
		( 109000, "00000000be71883ae1535bf6c1df6a8fd988598df79d3bb8031ecd1593955923")
		( 110000, "193a46588c23186441d968d3800c587bc934299d77a3082e34b714ca7cc51030")
		( 111000, "000000000ca9cea598b117baaa42be77878f045f3be1a3136f4efe6d9c5371ef")
		( 111881, "00000000213dd09b09668f109f6cc13f89fd4ef5e35780d4f940c11fe1f58ed6")

        ;

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
		( 0, hashGenesisBlockOfficial )   
        ;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // ppcoin: synchronized checkpoint (centrally broadcasted)
    uint256 hashSyncCheckpoint = 0;
    uint256 hashPendingCheckpoint = 0;
    CSyncCheckpoint checkpointMessage;
    CSyncCheckpoint checkpointMessagePending;
    uint256 hashInvalidCheckpoint = 0;
    CCriticalSection cs_hashSyncCheckpoint;

    // ppcoin: get last synchronized checkpoint
    CBlockIndex* GetLastSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            error("GetSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        else
            return mapBlockIndex[hashSyncCheckpoint];
        return NULL;
    }

    // ppcoin: only descendant of current sync-checkpoint is allowed
    bool ValidateSyncCheckpoint(uint256 hashCheckpoint)
    {
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        if (!mapBlockIndex.count(hashCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for received sync-checkpoint %s", hashCheckpoint.ToString().c_str());

        CBlockIndex* pindexSyncCheckpoint = mapBlockIndex[hashSyncCheckpoint];
        CBlockIndex* pindexCheckpointRecv = mapBlockIndex[hashCheckpoint];

        if (pindexCheckpointRecv->nHeight <= pindexSyncCheckpoint->nHeight)
        {
            // Received an older checkpoint, trace back from current checkpoint
            // to the same height of the received checkpoint to verify
            // that current checkpoint should be a descendant block
            CBlockIndex* pindex = pindexSyncCheckpoint;
            while (pindex->nHeight > pindexCheckpointRecv->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("ValidateSyncCheckpoint: pprev1 null - block index structure failure");
            if (pindex->GetBlockHash() != hashCheckpoint)
            {
                hashInvalidCheckpoint = hashCheckpoint;
                return error("ValidateSyncCheckpoint: new sync-checkpoint %s is conflicting with current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
            }
            return false; // ignore older checkpoint
        }

        // Received checkpoint should be a descendant block of the current
        // checkpoint. Trace back to the same height of current checkpoint
        // to verify.
        CBlockIndex* pindex = pindexCheckpointRecv;
        while (pindex->nHeight > pindexSyncCheckpoint->nHeight)
            if (!(pindex = pindex->pprev))
                return error("ValidateSyncCheckpoint: pprev2 null - block index structure failure");
        if (pindex->GetBlockHash() != hashSyncCheckpoint)
        {
            hashInvalidCheckpoint = hashCheckpoint;
            return error("ValidateSyncCheckpoint: new sync-checkpoint %s is not a descendant of current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
        }
        return true;
    }

    bool WriteSyncCheckpoint(const uint256& hashCheckpoint)
    {
        CTxDB txdb;
        txdb.TxnBegin();
        if (!txdb.WriteSyncCheckpoint(hashCheckpoint))
        {
            txdb.TxnAbort();
            return error("WriteSyncCheckpoint(): failed to write to db sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
        if (!txdb.TxnCommit())
            return error("WriteSyncCheckpoint(): failed to commit to db sync checkpoint %s", hashCheckpoint.ToString().c_str());
        txdb.Close();

        Checkpoints::hashSyncCheckpoint = hashCheckpoint;
        return true;
    }

    bool AcceptPendingSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint != 0 && mapBlockIndex.count(hashPendingCheckpoint))
        {
            if (!ValidateSyncCheckpoint(hashPendingCheckpoint))
            {
                hashPendingCheckpoint = 0;
                checkpointMessagePending.SetNull();
                return false;
            }

            CTxDB txdb;
            CBlockIndex* pindexCheckpoint = mapBlockIndex[hashPendingCheckpoint];
            if (!pindexCheckpoint->IsInMainChain())
            {
                CBlock block;
                if (!block.ReadFromDisk(pindexCheckpoint))
                    return error("AcceptPendingSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                if (!block.SetBestChain(txdb, pindexCheckpoint))
                {
                    hashInvalidCheckpoint = hashPendingCheckpoint;
                    return error("AcceptPendingSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                }
            }
            txdb.Close();

            if (!WriteSyncCheckpoint(hashPendingCheckpoint))
                return error("AcceptPendingSyncCheckpoint(): failed to write sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
            hashPendingCheckpoint = 0;
            checkpointMessage = checkpointMessagePending;
            checkpointMessagePending.SetNull();
            printf("AcceptPendingSyncCheckpoint : sync-checkpoint at %s\n", hashSyncCheckpoint.ToString().c_str());
            // relay the checkpoint
            if (!checkpointMessage.IsNull())
            {
                BOOST_FOREACH(CNode* pnode, vNodes)
                    checkpointMessage.RelayTo(pnode);
            }
            return true;
        }
        return false;
    }

    // Automatically select a suitable sync-checkpoint 
    uint256 AutoSelectSyncCheckpoint()
    {
        // Proof-of-work blocks are immediately checkpointed
        // to defend against 51% attack which rejects other miners block 

        // Select the last proof-of-work block
        const CBlockIndex *pindex = GetLastBlockIndex(pindexBest, false);
        // Search forward for a block within max span and maturity window
        while (pindex->pnext && (pindex->GetBlockTime() + CHECKPOINT_MAX_SPAN <= pindexBest->GetBlockTime() || pindex->nHeight + std::min(6, nCoinbaseMaturity - 20) <= pindexBest->nHeight))
            pindex = pindex->pnext;
        return pindex->GetBlockHash();
    }

    // Check against synchronized checkpoint
    bool CheckSync(const uint256& hashBlock, const CBlockIndex* pindexPrev)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        int nHeight = pindexPrev->nHeight + 1;

        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];

        if (nHeight > pindexSync->nHeight)
        {
            // trace back to same height as sync-checkpoint
            const CBlockIndex* pindex = pindexPrev;
            while (pindex->nHeight > pindexSync->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("CheckSync: pprev null - block index structure failure");
            if (pindex->nHeight < pindexSync->nHeight || pindex->GetBlockHash() != hashSyncCheckpoint)
                return false; // only descendant of sync-checkpoint can pass check
        }
        if (nHeight == pindexSync->nHeight && hashBlock != hashSyncCheckpoint)
            return false; // same height with sync-checkpoint
        if (nHeight < pindexSync->nHeight && !mapBlockIndex.count(hashBlock))
            return false; // lower height than sync-checkpoint
        return true;
    }

    bool WantedByPendingSyncCheckpoint(uint256 hashBlock)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint == 0)
            return false;
        if (hashBlock == hashPendingCheckpoint)
            return true;
        if (mapOrphanBlocks.count(hashPendingCheckpoint) 
            && hashBlock == WantedByOrphan(mapOrphanBlocks[hashPendingCheckpoint]))
            return true;
        return false;
    }

    // ppcoin: reset synchronized checkpoint to last hardened checkpoint
    bool ResetSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        const uint256& hash = mapCheckpoints.rbegin()->second;
        if (mapBlockIndex.count(hash) && !mapBlockIndex[hash]->IsInMainChain())
        {
            // checkpoint block accepted but not yet in main chain
            printf("ResetSyncCheckpoint: SetBestChain to hardened checkpoint %s\n", hash.ToString().c_str());
            CTxDB txdb;
            CBlock block;
            if (!block.ReadFromDisk(mapBlockIndex[hash]))
                return error("ResetSyncCheckpoint: ReadFromDisk failed for hardened checkpoint %s", hash.ToString().c_str());
            if (!block.SetBestChain(txdb, mapBlockIndex[hash]))
            {
                return error("ResetSyncCheckpoint: SetBestChain failed for hardened checkpoint %s", hash.ToString().c_str());
            }
            txdb.Close();
        }
        else if(!mapBlockIndex.count(hash))
        {
            // checkpoint block not yet accepted
            hashPendingCheckpoint = hash;
            checkpointMessagePending.SetNull();
            printf("ResetSyncCheckpoint: pending for sync-checkpoint %s\n", hashPendingCheckpoint.ToString().c_str());
        }

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            if (mapBlockIndex.count(hash) && mapBlockIndex[hash]->IsInMainChain())
            {
                if (!WriteSyncCheckpoint(hash))
                    return error("ResetSyncCheckpoint: failed to write sync checkpoint %s", hash.ToString().c_str());
                printf("ResetSyncCheckpoint: sync-checkpoint reset to %s\n", hashSyncCheckpoint.ToString().c_str());
                return true;
            }
        }

        return false;
    }

    void AskForPendingSyncCheckpoint(CNode* pfrom)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (pfrom && hashPendingCheckpoint != 0 && (!mapBlockIndex.count(hashPendingCheckpoint)) && (!mapOrphanBlocks.count(hashPendingCheckpoint)))
            pfrom->AskFor(CInv(MSG_BLOCK, hashPendingCheckpoint));
    }

    bool SetCheckpointPrivKey(std::string strPrivKey)
    {
        // Test signing a sync-checkpoint with genesis block
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = hashGenesisBlock;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        std::vector<unsigned char> vchPrivKey = ParseHex(strPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return false;

        // Test signing successful, proceed
        CSyncCheckpoint::strMasterPrivKey = strPrivKey;
        return true;
    }

    bool SendSyncCheckpoint(uint256 hashCheckpoint)
    {
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = hashCheckpoint;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        if (CSyncCheckpoint::strMasterPrivKey.empty())
            return error("SendSyncCheckpoint: Checkpoint master key unavailable.");
        std::vector<unsigned char> vchPrivKey = ParseHex(CSyncCheckpoint::strMasterPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return error("SendSyncCheckpoint: Unable to sign checkpoint, check private key?");

        if(!checkpoint.ProcessSyncCheckpoint(NULL))
        {
            printf("WARNING: SendSyncCheckpoint: Failed to process checkpoint.\n");
            return false;
        }

        // Relay checkpoint
        {
            LOCK(cs_vNodes);
            BOOST_FOREACH(CNode* pnode, vNodes)
                checkpoint.RelayTo(pnode);
        }
        return true;
    }

    // Is the sync-checkpoint outside maturity window?
    bool IsMatureSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];
        return (nBestHeight >= pindexSync->nHeight + nCoinbaseMaturity ||
                pindexSync->GetBlockTime() + nStakeMinAge < GetAdjustedTime());
    }

    // Is the sync-checkpoint too old?
    bool IsSyncCheckpointTooOld(unsigned int nSeconds)
    {
        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];
        return (pindexSync->GetBlockTime() + nSeconds < GetAdjustedTime());
    }
}

// ppcoin: sync-checkpoint master key
const std::string CSyncCheckpoint::strMasterPubKey = "0465be2bdbe73c00bf28984ca7a6f5963e61843a5522c6a180b19dedb0606a248e699739e029777d358ba0a5f8c81fe5af719767337c3e3eea105305bc93c6d81a";

std::string CSyncCheckpoint::strMasterPrivKey = "";

// ppcoin: verify signature of sync-checkpoint message
bool CSyncCheckpoint::CheckSignature()
{
    CKey key;
    if (!key.SetPubKey(ParseHex(CSyncCheckpoint::strMasterPubKey)))
        return error("CSyncCheckpoint::CheckSignature() : SetPubKey failed");
    if (!key.Verify(Hash(vchMsg.begin(), vchMsg.end()), vchSig))
        return error("CSyncCheckpoint::CheckSignature() : verify signature failed");

    // Now unserialize the data
    CDataStream sMsg(vchMsg, SER_NETWORK, PROTOCOL_VERSION);
    sMsg >> *(CUnsignedSyncCheckpoint*)this;
    return true;
}

// ppcoin: process synchronized checkpoint
bool CSyncCheckpoint::ProcessSyncCheckpoint(CNode* pfrom)
{
    if (!CheckSignature())
        return false;

    LOCK(Checkpoints::cs_hashSyncCheckpoint);
    if (!mapBlockIndex.count(hashCheckpoint))
    {
        // We haven't received the checkpoint chain, keep the checkpoint as pending
        Checkpoints::hashPendingCheckpoint = hashCheckpoint;
        Checkpoints::checkpointMessagePending = *this;
        printf("ProcessSyncCheckpoint: pending for sync-checkpoint %s\n", hashCheckpoint.ToString().c_str());
        // Ask this guy to fill in what we're missing
        if (pfrom)
        {
            pfrom->PushGetBlocks(pindexBest, hashCheckpoint);
            // ask directly as well in case rejected earlier by duplicate
            // proof-of-stake because getblocks may not get it this time
            pfrom->AskFor(CInv(MSG_BLOCK, mapOrphanBlocks.count(hashCheckpoint)? WantedByOrphan(mapOrphanBlocks[hashCheckpoint]) : hashCheckpoint));
        }
        return false;
    }

    if (!Checkpoints::ValidateSyncCheckpoint(hashCheckpoint))
        return false;

    CTxDB txdb;
    CBlockIndex* pindexCheckpoint = mapBlockIndex[hashCheckpoint];
    if (!pindexCheckpoint->IsInMainChain())
    {
        // checkpoint chain received but not yet main chain
        CBlock block;
        if (!block.ReadFromDisk(pindexCheckpoint))
            return error("ProcessSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        if (!block.SetBestChain(txdb, pindexCheckpoint))
        {
            Checkpoints::hashInvalidCheckpoint = hashCheckpoint;
            return error("ProcessSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
    }
    txdb.Close();

    if (!Checkpoints::WriteSyncCheckpoint(hashCheckpoint))
        return error("ProcessSyncCheckpoint(): failed to write sync checkpoint %s", hashCheckpoint.ToString().c_str());
    Checkpoints::checkpointMessage = *this;
    Checkpoints::hashPendingCheckpoint = 0;
    Checkpoints::checkpointMessagePending.SetNull();
    printf("ProcessSyncCheckpoint: sync-checkpoint at %s\n", hashCheckpoint.ToString().c_str());
    return true;
}
